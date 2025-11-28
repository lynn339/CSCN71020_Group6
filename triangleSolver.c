#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "triangleSolver.h"
#define EPSILON 0.0001
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

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

/**
 * Calculate triangle angles using Law of Cosines.
 *
 * Implementation Notes:
 * - Validates NULL pointers to prevent crashes
 * - Validates positive sides
 * - Uses Law of Cosines: cos(A) = (b?+ c?- a? / (2bc)
 * - Converts radians to degrees: angle * (180/?)
 */
int calculateTriangleAngles(double side1, double side2, double side3,
    double* angle1, double* angle2, double* angle3) {

    // STEP 1: Validate NULL pointers
    if (angle1 == NULL || angle2 == NULL || angle3 == NULL) {
        return 0;  // Error: NULL pointer
    }

    // STEP 2: Validate positive sides
    if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
        return 0;  // Error: non-positive sides
    }

    // STEP 3: Validate Triangle Inequality Theorem
    // Sum of any two sides must be greater than the third
    if (side1 + side2 <= side3 ||
        side2 + side3 <= side1 ||
        side1 + side3 <= side2) {
        return 0;  // Error: not a valid triangle
    }

    // STEP 4: Calculate angles using Law of Cosines
    // Formula: cos(A) = (b?+ c?- a? / (2bc)

    // angle1 is opposite to side1
    double cos_angle1 = (side2 * side2 + side3 * side3 - side1 * side1) / (2 * side2 * side3);

    // angle2 is opposite to side2
    double cos_angle2 = (side1 * side1 + side3 * side3 - side2 * side2) / (2 * side1 * side3);

    // angle3 is opposite to side3
    double cos_angle3 = (side1 * side1 + side2 * side2 - side3 * side3) / (2 * side1 * side2);

    // STEP 5: Convert from radians to degrees
    // acos() returns radians, we multiply by (180/?) to get degrees
    *angle1 = acos(cos_angle1) * (180.0 / M_PI);
    *angle2 = acos(cos_angle2) * (180.0 / M_PI);
    *angle3 = acos(cos_angle3) * (180.0 / M_PI);

    return 1;  // Success
}

