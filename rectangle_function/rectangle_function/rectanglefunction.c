#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void getPoints(int* x, int* y)
{
    printf("Enter a point (x, y): ");
    while (scanf("%d , %d", x, y) != 2)
    {
        printf("Invalid value, please enter a point (x, y): ");
        while (getchar() != '\n');
    }
}
