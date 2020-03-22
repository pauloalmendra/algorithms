#include <stdio.h>
#include <time.h>

int main(void)
{
    long length = 1000000000;
    int sum = 0;

    time_t t0;
    time_t tf;

    time(&t0);

    int i = 0;
    for(i = 1; i < length; i++)
    {
        if( ((i % 3) == 0 ) || ((i % 5) == 0) )
        {
            sum += i;
        }
    }
    
    time(&tf);

    clock_t clockF = clock();

    printf("t0 = %lu \n", t0);
    printf("tf = %lu \n", tf);
    printf("clockF = %f \n", (double)((double)clockF/CLOCKS_PER_SEC));
    printf("sum = %d \n", sum);
    
    return 0;
}