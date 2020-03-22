#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define IS_MULTIPLE(a,b)    ((a % b) == 0) ? true : false

int main(void)
{
    int n = 1000000;
    unsigned int array[n];
    memset(&array[0], 0x0, sizeof(array));

    int i = 0;
    int j = 0;
    int nbOfInvalid = 0;

    int iLimit = (int) sqrt(n) + 1;
    int jLimit = n;

    for(i = 2; i < iLimit; i++)
    {
        for(j = i + 1; j < jLimit; j++)
        {
            if( (j % i) == 0 )
            {
                // printf("i %.3d | j %.3d | z \n", i, j);
                array[j] = 1;
            }
        }
    }

    unsigned int primes[n];
    i = 0;
    j = 0;
    for(i = 2; i < n; i++)
    {
        if(array[i] == 0)
        {
            primes[j] = i;
            j++;
        }
    }

    // long number = 13195;
    long number = 600851475143;

    i = 0;
    int factor[12];
    int factorIdx = 0;
    
    do {
        if( (number % primes[i]) == 0)
        {
            factor[factorIdx] = primes[i];
            number = number / primes[i];

            i = 0;
            factorIdx++;
        }

        i++;
    } while(i != 10000);

    int nbOfFactors = factorIdx;
    char message[256];

    for(i = 0; i < nbOfFactors; i++)
    {
        printf(" %d ", factor[i]);
    }

    printf("\n");

    return 0;
}
