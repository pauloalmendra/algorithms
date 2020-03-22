#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define IS_MULTIPLE(a,b)    ((a % b) == 0) ? true : false
#define GOLDEN_RATIO        (double) (( (double) 1 + sqrt(5) ) / (double) 2)


void eratosthenes(int n)
{
    bool* ptr = calloc(n, sizeof(bool) * n);
    memset(ptr, 1, sizeof(bool) * n);

    long* primePtr = calloc(n, sizeof(long) * n);

    int i = 0;
    int j = 0;

    int iLimit = (int) sqrt(n) + 1;
    int jLimit = n;

    for(i = 2; i < iLimit; i++)
    {
        if(ptr[i] == true)
        {
            for(j = i + 1; j < jLimit; j++)
            {
                if( (j % i) == 0 )
                {
                    ptr[j] = false;
                }
            }
        }
    }

    long sum = 0;
    j = 0;
    for(i = 2; i < n; i++)
    {
        if(ptr[i] == true)
        {
            primePtr[j++] = i;
            sum += i;
        }
    }

    printf(" sum = %lu \n" , sum);
}

int main(void)
{
    clock_t start;
    clock_t end;
    double  cpuTimeUsed;

    start = clock();

    eratosthenes(2000000);

    end = clock();

    cpuTimeUsed = ((double)(end - start) / CLOCKS_PER_SEC);

    printf("\n CPU time used = %f \n", cpuTimeUsed);

    return 0;
}
