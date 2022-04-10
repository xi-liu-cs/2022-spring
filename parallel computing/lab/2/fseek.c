#include <stdio.h>

int main()
{
    FILE * p = fopen("num.txt", "r");
    fseek(p, 5, SEEK_SET);
    int c;
    while((c = fgetc(p)) != -1)
        printf("%c", c);
}