#include <stdio.h>
#include <stdlib.h>
// https://www.geeksforgeeks.org/c-program-find-direction-growth-stack/
void stack(int * main_local_addr)
{
    int f_local; //local variable of this function
    printf("main_loc_addr = %p\n", main_local_addr);
    printf("f_local = %p\n", &f_local);
    printf("diff = %d\n", abs(main_local_addr - &f_local));
    if(main_local_addr < &f_local)
        printf("stack grows up\n\n");
    else
        printf("stack grows down\n\n");
}

void heap(int * main_local_addr)
{
    int * heap_ptr = malloc(sizeof(int));
    printf("main_loc_addr = %p\n", main_local_addr);
    printf("heap_ptr = %p\n", heap_ptr);
    printf("diff = %d\n", abs(main_local_addr - heap_ptr));
    if(main_local_addr < heap_ptr)
        printf("heap grows up\n\n");
    else
        printf("heap grows down\n\n");
}

int main()
{
    int main_local;
    stack(&main_local);
    heap(&main_local);
}