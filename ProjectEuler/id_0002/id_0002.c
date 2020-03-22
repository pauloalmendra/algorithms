#include <stdio.h>
#include <time.h>
#include <math.h>

#define GOLDEN_RATIO 1.61803398874989484820

unsigned int getX(unsigned int n);

int main(void)
{
    unsigned int length = 35;

    unsigned int fibo[length];
    fibo[0] = 1;
    fibo[1] = 2;

    unsigned int sum = fibo[1]; 

    int i = 2;
    for(i = 2; i < length; i++)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];

        if( (fibo[i] % 2) == 0 ) 
        {
            sum += fibo[i];
            printf("fibo[%d] %u  sum %u\n", i, fibo[i], sum);
        }
    }

    return 0;
}

unsigned int getX(unsigned int n)
{
    return (unsigned int)( (pow(GOLDEN_RATIO, (double) n) - (pow(1 - GOLDEN_RATIO, (double) n)) ) / (sqrt(5.0)) );
}