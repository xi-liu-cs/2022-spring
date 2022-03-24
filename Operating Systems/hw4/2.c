#include <stdio.h>
#include <stdlib.h>

void chooseIngredients(int *p, int *t, int *m)
{
    *p = 1;
    *m = 1;
}

int main()
{
    int paper = 0;
    int tobacco = 0;
    int match = 0; 
    printf("paper: %d\n tobacco: %d\n match: %d\n",
    paper, tobacco, match);

    chooseIngredients(&paper, &tobacco, &match);
    
    printf("paper: %d\n tobacco: %d\n match: %d\n",
    paper, tobacco, match);
}