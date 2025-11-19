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
    return fabs(dot) < 1e-6; // dot = 0 ¡ú right angle
}