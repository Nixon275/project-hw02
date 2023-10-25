#include<stdio.h>
#include<complex.h>
#include "../inc/cmplx.h"
#include "../src/cmplx.c"
int main ()
{
    cmplx_t a = {1.0f,2.0f};
    complex double x = 1 + 2*I;
    
    if (cmplx_phs(a) - carg(x)<10^-9)
    printf("Success.\n");
    else
    printf("Failure.\n");
    return 0;
}