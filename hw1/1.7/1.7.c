#include <stdio.h>
#include <math.h>
#include <stdbool.h>

const int maxSize = 1000;

int main()
{
    int input = 0;
    printf("Enter the number : ");
    scanf("%d", &input);
    bool isPrime[maxSize];
    for (int i = 0; i < input; ++i)
    {
        isPrime[i] = true;
    }
    for (int i = 2; i < input; ++i) 
    {
        if (isPrime[i])
        {
            for (int j = 2 * i; j < input; j += i) 
            {
                isPrime[j] = false;
            }
        }
    }
    printf("All prime numbers less than %d are : \n", input);
    for (int i = 2; i < input; ++i)
    {
        if (isPrime[i])
        {
            printf("%d ", i);
        }
    }
    return 0;
}
