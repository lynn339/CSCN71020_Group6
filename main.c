#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "main.h"
#include "triangleSolver.h"

// Test helper function
void testClassifyTriangle(const char* testName, double s1, double s2, double s3, const char* expected) {
    char* result = classifyTriangle(s1, s2, s3);

    if (strcmp(result, expected) == 0) {
        printf("PASS: % s\n", testName);
        printf("  Input: (%.2f, %.2f, %.2f)\n", s1, s2, s3);
        printf("  Expected: %s | Got: %s\n\n", expected, result);
    }
    else {
        printf("FAIL: %s\n", testName);
        printf("  Input: (%.2f, %.2f, %.2f)\n", s1, s2, s3);
        printf("  Expected: %s | Got: %s\n\n", expected, result);
    }
}

int main() {
    printf("===== Triangle Classification Tests =====\n\n");

    // TEST 1: Equilateral triangle
    testClassifyTriangle("Test 1: Equilateral (5,5,5)",
        5.0, 5.0, 5.0,
        "Equilateral");

	// TEST 2: Isosceles triangle
    testClassifyTriangle("Test 2: Isosceles (5,5,3)",
        5.0, 5.0, 3.0,
		"Isosceles");

	// TEST 3: Scalene triangle
    testClassifyTriangle("Test 3: Scalene (3,4,5)",
		3.0, 4.0, 5.0,
		"Scalene");

	// TEST 4: Invalid triangle with zero side
    testClassifyTriangle("Test 4: Invalid (0,5,5)",
        0.0, 5.0, 5.0,
        "Not a triangle");

    // TEST 5: Invalid - negative side
    testClassifyTriangle("Test 5: Invalid - Negative Side (-3,4,5)",
        -3.0, 4.0, 5.0, "Not a triangle"); 

    // TEST 6: Invalid - triangle inequality violation
    testClassifyTriangle("Test 6: Invalid - Triangle Inequality (1,2,10)",
        1.0, 2.0, 10.0, "Not a triangle");

    printf("\nPress Enter to exit...");
    getchar();
    return 0;
}
