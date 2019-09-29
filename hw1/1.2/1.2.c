#include <stdio.h>

int main()
{
    int dividend = 0;
    int divider = 0;
    int quotient = 0;
    printf("Enter the dividend : ");
    scanf("%d", &dividend);
    printf("Enter the divider : ");
    scanf("%d", &divider);
    while (dividend >= divider) 
    {
        ++quotient;
        dividend -= divider;
    }
    printf("result: %d", quotient);
    return 0;
}