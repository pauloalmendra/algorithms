#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>


/**
 * Sieve of Eratosthenes
 * ---------------------
 * 
 * Make a list of all the integers less than or equal to n (and greater than one).
 * Strike out the multiples of all primes less than or equal to the square root of n, 
 * then the numbers that are left are the primes.
 * 
 * Example:
 * 
 * 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 
 * x   '   '   '   '     '      '     '     '     '     '     '     '     '     '
 *   x           '                 '                 '           '     x
 *       x
 *           x
 *                     x
 *                           x
 *                                       x
 *                                            x
 *                                                        x
 *                                                                          x
 * 
 * prime numbers 2 3 5 7 11 13 17 19 23 29
 * 
 */
void eratosthenes(int n)
{
    bool* ptr = calloc(n, sizeof(bool) * n);
    printf(" sizeof(bool) * n = %lu \n" , sizeof(bool) * n);
    memset(ptr, 1, sizeof(bool) * n);

    long* primePtr = calloc(n, sizeof(long) * n);
    printf(" sizeof(long) * n = %lu \n" , sizeof(long) * n);

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
}