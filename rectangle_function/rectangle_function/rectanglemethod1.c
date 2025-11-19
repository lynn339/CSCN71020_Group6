#include <stdio.h>
#include <math.h>


typedef struct {
    double x;
    double y;
} Point;

// calculate the distance between two points
double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
