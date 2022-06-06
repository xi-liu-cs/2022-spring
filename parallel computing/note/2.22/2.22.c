#include <stdio.h>

void f1(char * p)
{
    p = "abc";
    printf("stk: %s\n", p);
}

void f2(char ** p)
{
    *p = "y";
}

int comp(int x, int y)
{
    return x > y;
}

int t(int x, int y, int (*comp)(int, int))
{
    return (*comp)(x, y);   // comp(x, y)
}

typedef struct s
{
    int a;
    float b;
}s;


int main()
{
    char * p = "x";
    printf("%s\n", p);
    f1(p);
    printf("after f1: %s\n", p);
    f2(&p);
    printf("after f2: %s\n", p);

    int x = 2, y = 1;
    printf("t() = %d\n", t(x, y, comp));

    printf("comp = %p\n", comp);
    printf("*comp = %p\n", *comp);

    s st;
    st.a = 3;
    st.b = 2.0;
    printf("a = %d, b = %f\n", st.a, st.b);
}