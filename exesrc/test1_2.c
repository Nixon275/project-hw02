#include<stdio.h>
#include<complex.h>
#include "../inc/cmplx.h"
#include "../src/cmplx.c"
int main ()
{
    cmplx_t a = {1.0f,2.0f};
    cmplx_t b = {3.0f,4.0f};
    cmplx_t c;
    cmplx_mul(a,b,c);
    
    complex double x = 1 + 2*I;
    complex double y = 3 + 4*I;
    complex double z = x*y;

    if (c[0]-creal(z)<10^-9 && c[1]-cimag(z)<10^-9)
    printf("Success.\n");
    else
    printf("Failure.\n");
    return 0;
}