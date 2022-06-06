#include <stdio.h>
#include <string.h>

int main()
{
    char c = '\0';
    char c0 = 1;
    char c1 = 0;
    char * c2 = "\0";
    char * c3 = "\0a";
    char * c4 = "a\0";
    char * c5 = "a\1";
    printf("c = %c\n", c);
    printf("c = %d\n", c);
    printf("c0 = %c\n", c0);
    printf("c0 = %d\n", c0);
    printf("c1 = %c\n", c1);
    printf("c1 = %d\n", c1);
    printf("c len = %d\n", strlen(&c));
    printf("c0 len = %d\n", strlen(&c0));
    printf("c1 len = %d\n", strlen(&c1));
    printf("c2 len = %d\n", strlen(c2));
    printf("c3 len = %d\n", strlen(c3));
    printf("c4 len = %d\n", strlen(c4));
    printf("c5 len = %d\n", strlen(c5));
}
