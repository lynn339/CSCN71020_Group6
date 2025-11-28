#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

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
long long dot_product(Point pA, Point pB, Point pC) // 
{
	// store the value as long long
	long long ABx = (long long)pB.x - pA.x; 
	long long ABy = (long long)pB.y - pA.y;
	long long ACx = (long long)pC.x - pA.x;
	long long ACy = (long long)pC.y - pA.y;


bool is_rectangle(Point points[4])
{
	Point p1 = points[0];
	Point p2 = points[1];
	Point p3 = points[2];
	Point p4 = points[3];
	//calculate using dot product
	int dot1 = (p2.x - p1.x) * (p4.x - p1.x) + (p2.y - p1.y) * (p4.y - p1.y);
	int dot2 = (p1.x - p2.x) * (p3.x - p2.x) + (p1.y - p2.y) * (p3.y - p2.y);
	int dot3 = (p2.x - p3.x) * (p4.x - p3.x) + (p2.y - p3.y) * (p4.y - p3.y);
	int dot4 = (p3.x - p4.x) * (p1.x - p4.x) + (p3.y - p4.y) * (p1.y - p4.y);
	if (dot1 == 0 && dot2 == 0 && dot3 == 0 && dot4 == 0)
		return true;
	else
		return false;

	bool is_right_angle = (dot == 0);
	return midpoints_equal && is_right_angle;
}

void calculate_area(Point points[4])
{
	double side1 = distanceCalculate(points[0], points[1]);
	double side2 = distanceCalculate(points[1], points[2]);
	double area = side1 * side2;
	printf("The area is: %.2f\n", area);

}

//int main()
//{
//	Point points[4];
//	getPoints(points);
//	if (is_rectangle(points)) {
//		printf("The points form a rectangle.\n");
//		calculate_area(points);
//	}
//	else {
//		printf("The points do not form a rectangle.\n");
//	}
//	double perimeter = calculate_perimeter(points);
//	printf("The perimeter is: %.2f\n", perimeter);
//	return 0;
//}

