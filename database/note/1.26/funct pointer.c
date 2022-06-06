#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// https://www.geeksforgeeks.org/function-pointer-in-c/

void f(char * str)
{
    printf("str = %s\n", str);
}

void person1(char * name, int age)
{
    printf("person1->name = %s\nperson1->age = %d\n", name, age);
}

void person2(char * name, int age)
{
    printf("person2->name = %s\nperson2->age = %d\n", name, age);
}

int compare(const void * a, const void * b)
{
    if(!*(char *)a || !*(char *)b)
        return 0;
    // printf("a = %s, b = %s, d = %d\n", a, b, *(char *)a - *(char *)b);
    return *(char *)a - *(char *)b;
}

int main()
{
    void (* f_ptr)(char *) = &f;
    (*f_ptr)("xi");

    void (* f_ptr2)(char *) = f;
    f_ptr2("liu");

    void (* f_ptr_arr[])(char *, int) = {person1, person2};
    (*f_ptr_arr[0])("yuewen", 20);
    (**(f_ptr_arr + 1))("xi", 19);

    char a[] = "edcba";
    int len = sizeof(a) / sizeof(*a);
    qsort(a, len, sizeof(char), compare);
    printf("a = %s\n", a);
}