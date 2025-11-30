#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "main.h"
#include "triangleSolver.h"
#include "corner.h"
#include "rectangle1.h"

int side = 0;

int main() {
    bool continueProgram = true;

    while (continueProgram) {
        printWelcome();
        int shapeChoice = printShapeMenu();

        switch (shapeChoice)
        {
        case 1:  // TRIANGLE
            printf_s("Triangle selected.\n\n");
            analyzeTriangleWithAngles();
            break;

        case 2:  // RECTANGLE - NEW!
            printf_s("Rectangle selected.\n\n");
            analyzeRectangle();
            break;

        case 3:  // RECTANGLE - SPARE METHOD
            printf_s("Rectangle(Spare Method) selected.\n\n");
            analyzeRectangleSpare();
            break;

        case 0:  // EXIT
            continueProgram = false;
            break;

        default:
            printf_s("Invalid value entered.\n");
            break;
        }
    }

    printf_s("\nThank you for using Polygon Checker!\n");
    return 0;
}

void printWelcome() {
    printf_s("\n");
    printf_s(" **********************\n");
    printf_s("**     Welcome to     **\n");
    printf_s("**   Polygon Checker  **\n");
    printf_s(" **********************\n");
}

int printShapeMenu() {
    printf_s("1. Triangle\n");
    printf_s("2. Rectangle\n");
    printf_s("3. Rectangle(Spare Method)\n");
    printf_s("0. Exit\n");

    int shapeChoice;
    printf_s("Enter number: ");
    scanf_s("%d", &shapeChoice);

    return shapeChoice;
}

// TRIANGLE ANALYSIS
void analyzeTriangleWithAngles(void) {
    double triangleSides[3] = { 0.0, 0.0, 0.0 };

    printf_s("Enter the three sides of the triangle: ");
    for (int i = 0; i < 3; i++) {
        scanf_s("%lf", &triangleSides[i]);
    }

    // Classify
    char* triangleType = classifyTriangle(
        triangleSides[0],
        triangleSides[1],
        triangleSides[2]
    );

    printf_s("\n--- ANALYSIS RESULTS ---\n");
    printf_s("Triangle Type: %s\n", triangleType);

    // Calculate angles if valid
    if (strcmp(triangleType, "Not a triangle") != 0) {
        double angle1, angle2, angle3;

        int result = calculateTriangleAngles(
            triangleSides[0],
            triangleSides[1],
            triangleSides[2],
            &angle1, &angle2, &angle3
        );

        if (result == 1) {
            printf_s("\nInterior Angles:\n");
            printf_s("  Angle 1 (opposite side %.2f): %.2f degrees\n",
                triangleSides[0], angle1);
            printf_s("  Angle 2 (opposite side %.2f): %.2f degrees\n",
                triangleSides[1], angle2);
            printf_s("  Angle 3 (opposite side %.2f): %.2f degrees\n",
                triangleSides[2], angle3);

            double sum = angle1 + angle2 + angle3;
            printf_s("\nSum of angles: %.2f degrees\n", sum);

            if (sum >= 179.9 && sum <= 180.1) {
                printf_s("Verification: Sum equals 180 degrees ?\n");
            }
        }
    }
    else {
        printf_s("\nThese sides do not form a valid triangle.\n");
    }

    printf_s("========================\n");
}

// RECTANGLE SPARE METHOD ANALYSIS
void analyzeRectangleSpare(void) {
    Dot p1, p2, p3, p4;

    printf_s("Enter 4 points (x y on each line):\n");
    printf_s("Point 1: "); scanf_s("%lf %lf", &p1.x, &p1.y);
    printf_s("Point 2: "); scanf_s("%lf %lf", &p2.x, &p2.y);
    printf_s("Point 3: "); scanf_s("%lf %lf", &p3.x, &p3.y);
    printf_s("Point 4: "); scanf_s("%lf %lf", &p4.x, &p4.y);

    printf_s("\n--- ANALYSIS RESULTS (Spare Method) ---\n");
    checkRectangleMethod1(p1, p2, p3, p4);
    printf_s("========================\n");
}

// RECTANGLE ANALYSIS
void analyzeRectangle(void) {
    Point points[4];

    // Get 4 corner points
    getPoints(points);

    // Sort points for consistent ordering
    Point sorted[4];
    sort_points(points, sorted);

    printf_s("\n--- ANALYSIS RESULTS ---\n");

    // Check if it's a rectangle
    if (is_rectangle(sorted)) {
        printf_s("Shape Type: Rectangle \n");

        // Calculate perimeter
        double perimeter = calculate_perimeter(sorted);
        printf_s("\nPerimeter: %.2f units\n", perimeter);

        // Calculate area
        printf_s("\n");
        calculate_area(sorted);  // This function prints directly

    }
    else {
        printf_s("Shape Type: Not a rectangle \n");
        printf_s("\nThe points do not form a valid rectangle.\n");

        // Still show perimeter
        double perimeter = calculate_perimeter(sorted);
        printf_s("Perimeter: %.2f units\n", perimeter);
    }

    printf_s("========================\n");
}