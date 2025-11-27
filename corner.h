
#ifndef GETCORNER_H
#define GETCORNER_H
typedef struct Point
{
	int x;
	int y;
}Point;
void getPoints(Point points[4]);
double distanceCalculate(Point p1, Point p2);
double calculate_perimeter(Point sorted_points[4]);
bool is_rectangle(Point points[4]);

#endif // !RECTANGLEFUNCTION_H#pragma once
