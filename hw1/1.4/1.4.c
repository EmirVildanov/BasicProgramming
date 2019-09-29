#include <stdio.h>

int digitsSum(number)
{
    int sum = number / 100 + (number % 100) / 10 + (number % 100) % 10;
    return sum;
}

int main()
{
    int differentSums[28] = {0};
    int newSum = 0;
    int answer = 0;
    for (int i = 0; i < 1000; ++i)
    {
        newSum = digitsSum(i);
        differentSums[newSum] += 1;
    }
    for (int i = 0; i < 28; ++i)
    {
        answer += differentSums[i] ^ 2;
    }
    printf("The answer is: %d", answer);
    return 0;
}