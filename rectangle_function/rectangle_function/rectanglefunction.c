#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "rectangle.h" 
void getPoints(int *x, int *y)
{
    int i = 0;
    printf("Enter point %d (x, y) : ", i + 1);
    while (scanf_s("%d , %d", x, y) != 2)
    {
        printf("Invalid value, please enter a point (x, y): ");
        while (getchar() != '\n');
    }
}

