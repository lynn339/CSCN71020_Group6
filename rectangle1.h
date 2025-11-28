#ifndef RECTANGLE1_H
#define RECTANGLE1_H
typedef struct {
    double x;
    double y;
} Point; 
double distance(Point a, Point b);
bool isRightAnglePoint(Point a, Point b, Point c);

// DoublePoint °æ±¾
double distanceDouble(DoublePoint a, DoublePoint b);
bool isRightAngleDouble(DoublePoint a, DoublePoint b, DoublePoint c);
void checkRectangleMethod1(DoublePoint p1, DoublePoint p2, DoublePoint p3, DoublePoint p4);

#endif