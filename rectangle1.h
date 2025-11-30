#ifndef RECTANGLE1_H
#define RECTANGLE1_H

#include <stdbool.h>

typedef struct Dot {
    double x;
    double y;
} Dot;

double distance(Dot a, Dot b);
bool isRightAngle(Dot a, Dot b, Dot c);
void checkRectangleMethod1(Dot p1, Dot p2, Dot p3, Dot p4);
double calculate_perimeter(Dot pts[4]);
void calculate_area(Dot pts[4]);

#endif // RECTANGLE1_H