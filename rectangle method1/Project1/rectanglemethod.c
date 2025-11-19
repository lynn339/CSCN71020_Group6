#include <stdio.h>
#include <math.h>
#include <stdbool.h>


typedef struct {
    double x;
    double y;
} Point;

// calculate the distance between two points
double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
// check if angle ABC is a right angle
bool isRightAngle(Point a, Point b, Point c) {
    double x1 = a.x - b.x;
    double y1 = a.y - b.y;
    double x2 = c.x - b.x;
    double y2 = c.y - b.y;

    double dot = x1 * x2 + y1 * y2;
    return fabs(dot) < 1e-6; // dot = 0 is right angle
}
// check if the four points form a rectangle and calculate perimeter and area
void checkRectangleMethod1(Point p1, Point p2, Point p3, Point p4) {
    double d12 = distance(p1, p2);
    double d23 = distance(p2, p3);
    double d34 = distance(p3, p4);
    double d41 = distance(p4, p1);

    bool right1 = isRightAngle(p4, p1, p2);
    bool right2 = isRightAngle(p1, p2, p3);
    bool right3 = isRightAngle(p2, p3, p4);
    bool right4 = isRightAngle(p3, p4, p1);

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

int main() {
    Point a = { 0, 0 };
    Point b = { 4, 0 };
    Point c = { 4, 3 };
    Point d = { 0, 3 };

    checkRectangleMethod1(a, b, c, d);

    return 0;
}
