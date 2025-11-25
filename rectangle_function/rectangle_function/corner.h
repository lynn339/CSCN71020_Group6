
#ifndef GETCORNER_H
#define GETCORNER_H
typedef struct Point
{
	int x;
	int y;
}Point;
void getPoints(Point points[4]);
double distanceCalculate(Point p1, Point p2);
void sort_points_by_angle(Point points[], int n);
double calculate_perimeter(Point sorted_points[], int n);
bool is_rectangle_and_calculate_area(Point sorted_points[], double* area, double tolerance);

#endif // !RECTANGLEFUNCTION_H#pragma once
