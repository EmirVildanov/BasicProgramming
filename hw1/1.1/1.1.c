#include <stdio.h>

int main() {
    int input = 0;
    int answer = 0;
    int squareInput = 0 ;
    printf("Enter the x : \n");
    scanf("%d", &input);
    squareInput = input * input;
    answer = squareInput * (squareInput + input + 1) + input + 1;
    printf("result: %d", answer);
    return 0;
}