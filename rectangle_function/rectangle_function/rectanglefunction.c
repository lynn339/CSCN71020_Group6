#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void getPoints(int *x, int *y)
{
    while (scanf_s("%d , %d", x, y) != 2)
    {
        printf("Invalid value, please enter a point (x, y): ");
        while (getchar() != '\n');
    }
}

int main()
{
    int x[4], y[4];
    int i;
    for (i = 0; i < 4; i++)
    {
        printf("Enter point %d (x, y) : ", i + 1);
        getPoints(&x[i], &y[i]);
        
    }
    for (i = 0; i < 4; i++)
    {
        printf("The point %d is %d %d\n", i + 1, x[i], y[i]);
    }
    return 0;
    
}
