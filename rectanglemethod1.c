#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "corner.h"
#include "rectangle1.h"

// -------------------- Point °æ±¾ --------------------
double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

typedef struct {
    double x;
    double y;
} Point;

// -------------------- DoublePoint °æ±¾ --------------------
double distanceDouble(DoublePoint a, DoublePoint b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool isRightAngleDouble(DoublePoint a, DoublePoint b, DoublePoint c) {
    double x1 = a.x - b.x;
    double y1 = a.y - b.y;
    double x2 = c.x - b.x;
    double y2 = c.y - b.y;
    double dot = x1 * x2 + y1 * y2;
    return fabs(dot) < 1e-6;
}

void checkRectangleMethod1(DoublePoint p1, DoublePoint p2, DoublePoint p3, DoublePoint p4) {
    double d12 = distanceDouble(p1, p2);
    double d23 = distanceDouble(p2, p3);
    double d34 = distanceDouble(p3, p4);
    double d41 = distanceDouble(p4, p1);

    bool right1 = isRightAngleDouble(p4, p1, p2);
    bool right2 = isRightAngleDouble(p1, p2, p3);
    bool right3 = isRightAngleDouble(p2, p3, p4);
    bool right4 = isRightAngleDouble(p3, p4, p1);

    bool isRectangle =
        right1 && right2 && right3 && right4 &&
        fabs(d12 - d34) < 1e-6 &&
        fabs(d23 - d41) < 1e-6;

    double perimeter = d12 + d23 + d34 + d41;
    printf("Perimeter: %.2f\n", perimeter);

    if (isRectangle) {
        double area = d12 * d23;
        printf("This is a rectangle.\n");
        printf("Area: %.2f\n", area);
    }
    else {
        printf("This is NOT a rectangle.\n");
        printf("Area: N/A\n");
    }
}