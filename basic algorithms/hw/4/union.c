#include <stdio.h>

typedef union uni
{
    int ival;
    float fval;
    char * sval;
} uni;

enum {_int, _float, _char};

int main()
{
    int utype = _int;
    uni u;
    u.ival = 20;
    if(utype == _int)
        printf("ival = %d\n", u.ival);
    u.fval = 4.0;
    utype = _float;
    if(utype == _float)
        printf("fval = %f\n", u.fval);
    u.sval = "a";
    utype = _char;
    if(utype == _char)
    printf("sval = %s\n", u.sval);
    printf("ival should be overwritten, ival = %d\n", u.ival);
    printf("sizeof(char *) = %d\n", sizeof(char *));
    printf("sizeof(u) = %d\n", sizeof(u));
}