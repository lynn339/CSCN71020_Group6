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

    printf("\nPress Enter to exit...");
    getchar();
    return 0;
}