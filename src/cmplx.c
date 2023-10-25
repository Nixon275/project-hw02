#include<stdio.h>
#include<math.h>
#include "cmplx.h"
#define M_PI 3.14159265358979323846


void cmplx_div(cmplx_t a, cmplx_t b, cmplx_t c)
{
    if (b[0]!=0 && b[1]!=0)
    {
        c[0]=(a[0]*b[0]+a[1]*b[1])/(b[0]*b[0]+b[1]*b[1]);
        c[1]=(a[1]*b[0]-a[0]*b[1])/(b[0]*b[0]+b[1]*b[1]);
    }
    else
    printf("Error: division by zero.");
    
}

void cmplx_mul(cmplx_t a, cmplx_t b, cmplx_t c)
{
    c[0]=a[0]*b[0]-a[1]*b[1];
    c[1]=a[0]*b[1]+a[1]*b[0];
}

double cmplx_mag(cmplx_t a)
{
    return sqrt(a[0]*a[0]+a[1]*a[1]);
}

double cmplx_phs(cmplx_t a)
{
    return atan(a[1]/a[0]);
}

double cmplx_real(double mag, double phs)
{
    return cos(phs)*mag;
}

double cmplx_imag(double mag, double phs)
{
    return sin(phs)*mag;
}

void cmplx_dft(cmplx_t *input, cmplx_t *output, int N)
{
    for (int k=0;k<N;k++)
    {
    float real=0;
    float img=0;
        
        for (int n=0;n<N;n++)
        {
            real+=input[n][0]*cos(2*M_PI*n*k / N) + input[n][1]*sin(2*M_PI*n*k / N);
            img+= input[n][0]*sin(2*M_PI*n*k / N)*-1 + input[n][1]*cos(2*M_PI*n*k / N);
        }

    output[k][0]=real;
    output[k][1]=img;
    }
}

void cmplx_idft(cmplx_t *input, cmplx_t *output, int N)
{
    for (int k=0;k<N;k++)
    {
    float real=0;
    float img=0;
        
        for (int n=0;n<N;n++)
        {
            real+=input[n][0]*cos(2*M_PI*n*k / N) - input[n][1]*sin(2*M_PI*n*k / N);
            img+= input[n][0]*sin(2*M_PI*n*k / N) + input[n][1]*cos(2*M_PI*n*k / N);
        }

    output[k][0]=real/N;
    output[k][1]=img/N;
    }
}


