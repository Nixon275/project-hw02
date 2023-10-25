#include<stdio.h>
#include<complex.h>
#include "../inc/cmplx.h"
#include "../src/cmplx.c"
int main ()
{
    cmplx_t a = {1.0,2.0};
    complex double x = 1 + 2*I;
    
    if (cmplx_imag(cmplx_mag(a), cmplx_phs(a)) - cimag(x)<10^-9)
    printf("Success.\n");
    else
    printf("Failure.\n");
    return 0;
}