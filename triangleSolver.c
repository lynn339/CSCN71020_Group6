#include <stdio.h>
#include <stdbool.h>

#include "triangleSolver.h"

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2))
	{
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene triangle";
	}

	return result;
}
// Implement classifyTriangle 
char* classifyTriangle(double side1, double side2, double side3) {
    // Validation 1: sides must be positive
    if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
        return "Not a triangle";
    }

    // Validation 2: Triangle Inequality Theorem
    // Sum of any 2 sides must be greater than the 3rd side
    if (side1 + side2 <= side3 ||
        side2 + side3 <= side1 ||
        side1 + side3 <= side2) {
        return "Not a triangle";
    }

    // Check if all 3 sides are equal
    if (side1 == side2 && side2 == side3) {
        return "Equilateral";
    }
    // Check if exactly 2 sides are equal
    else if (side1 == side2 || side2 == side3 || side1 == side3) {
        return "Isosceles";
    }
    // All sides different
    else {
        return "Scalene";
    }
}