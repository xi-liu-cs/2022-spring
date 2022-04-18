#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

// sequential
int main(int argc, char *argv[])
{
    int bins = atoi(argv[1]);
    int threads = atoi(argv[2]);
    int p = 0; // number of floats

    // read file
    FILE *fp;
    fp = fopen(argv[3], "r");
    fscanf(fp, "%d", &p);

    double *floats = malloc(p * sizeof(double));
    // int count = 0;
    for (int i = 0; i < p; ++i)
    {
        fscanf(fp, "%lf", &floats[i]);
        printf("%lf\n", floats[i]);
    }
    fclose(fp);

    // make bins and get ranges of each bin
    int bin[bins];
    int min[bins];
    int max[bins];

    int binSize = 100 / bins;
    for (int i = 0; i < bins; i++)
    {
        bin[i] = 0;
        min[i] = 0 + binSize * i;
        if (i == bins - 1)
        {
            max[i] = 100;
        }
        else
        {
            max[i] = binSize + binSize * i;
        }
        printf("bin[%d] - min: %d, max:%d\n", i, min[i], max[i]);
    }

    int workSize = p / threads;
    double t_start, t_taken;
    int my_rank, start, end, i, j;
// make threads
#pragma omp parallel num_threads(threads) default(none) private(my_rank, start, end, i, j) shared(p, bins, floats, bin, min, max, workSize, t_start)
    {
        t_start = omp_get_wtime();
        my_rank = omp_get_thread_num();
        start = 0 + workSize * my_rank;
        if (my_rank == omp_get_num_threads() - 1) // last thread
        {
            end = p;
        }
        else
        {
            end = workSize + workSize * my_rank;
        }

        printf("thread %d - start index: %d, end index: %d\n", my_rank, start, end);
#pragma omp parallel for
        for (j = start; j < end; j++)
        {
            printf("j = %d\n");
            for (i = 0; i < bins; i++)
            {
                printf("thread %d: checking floats[%d] = %f for bin[%d]", my_rank, j, floats[j], i);
                if (floats[j] > min[i] && floats[j] <= max[i])
                {
                    printf("thread %d: %f into bin[%d]\n", my_rank, floats[j], i);
#pragma omp atomic
                    bin[i]++;
                }
            }
        }
    }

    t_taken = omp_get_wtime() - t_start;

    free(floats);

    for (int i = 0; i < bins; i++)
    {
        printf("bin[%d] = %d\n", i, bin[i]);
    }

    return 0;
}