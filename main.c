#include <stdio.h>
#include "triangleSolver.h"

int main() {
    double side1, side2, side3;

    printf("Enter side 1: ");
    scanf_s("%lf", &side1);

    printf("Enter side 2: ");
    scanf_s("%lf", &side2);

    printf("Enter side 3: ");
    scanf_s("%lf", &side3);

    char* result = classifyTriangle(side1, side2, side3);

    printf("\nTriangle type: %s\n", result);

    return 0;
}