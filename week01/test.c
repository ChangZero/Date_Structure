#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double power(int x)
{
    int i;
    double result = 1;
    for(i=0;i<x;i++)
        result *=2;
    return result;
}
void main(void)
{
    clock_t start, finish;
    int i;
    double n, y, duration;
    start = clock();


    n = power(10);
    for(i=0;i<=n;i++)
        y = y+1;

    finish = clock();
    duration = (double)(finish - start);
    printf("y = %.0f, duration = %.0f\n", y, duration);
}