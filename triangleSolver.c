#include <stdio.h>
#include <stdbool.h>

#include "triangleSolver.h"

#include <math.h>

#define EPSILON 0.0001

// Helper function for floating-point comparison
int areDoublesEqual(double a, double b) {
    return fabs(a - b) < EPSILON;
}

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
    if (side1 + side2 <= side3 ||
        side2 + side3 <= side1 ||
        side1 + side3 <= side2) {
        return "Not a triangle";
    }

    // Use tolerance-based comparison
    int side1_eq_side2 = areDoublesEqual(side1, side2);
    int side2_eq_side3 = areDoublesEqual(side2, side3);
    int side1_eq_side3 = areDoublesEqual(side1, side3);

    // Classification
    if (side1_eq_side2 && side2_eq_side3) {
        return "Equilateral";
    }
    else if (side1_eq_side2 || side2_eq_side3 || side1_eq_side3) {
        return "Isosceles";
    }
    else {
        return "Scalene";
    }
}
