#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct Point
{
	int x;
	int y;
}Point;
void getPoints(Point points[4])
{
	
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		printf("Enter #%d point coordinate: ", i + 1);
		while (scanf_s("%d %d", &points[i].x, &points[i].y) != 2)
		{
			printf("Invalid input. Please enter two integers for x and y coordinates: ");
			while (getchar() != '\n'); // Clear the input buffer
		}
	}
	
}

double distanceCalculate(Point p1, Point p2)
{
	double dx = (double)(p2.x - p1.x);
	double dy = (double)(p2.y - p1.y);
	return sqrt(pow(dx, 2)+pow(dy, 2));
}

double calculate_perimeter(Point sorted_points[4])
{
	double perimeter = 0.0;
	int i;
	for (i = 0; i < 4; i++)
	{
		Point current_point = sorted_points[i];
		Point next_point = sorted_points[(i + 1) % 4]; // Wrap around to the first point
		perimeter += distanceCalculate(current_point, next_point);
	}
	return perimeter;
}



