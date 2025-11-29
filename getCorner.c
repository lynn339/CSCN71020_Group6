#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#define ANGLE_EPSILON 0.0000001
typedef struct Point
{
	int x;
	int y;
}Point;
typedef struct anglepoints {
	Point p;
	double angle;
} AnglePoint;

// qsort comparator function to sort points by angle
int compare_angle(const void* a, const void* b) {
	double angle_a = ((AnglePoint*)a)->angle;
	double angle_b = ((AnglePoint*)b)->angle;
	if (fabs(angle_a - angle_b) < ANGLE_EPSILON) {
		return 0;
	}

	// 2. 正常比較
	if (angle_a < angle_b) {
		return -1;
	}
	else {
		return 1; // 只有當 angle_a > angle_b 時執行
	}
}

void sort_points(Point unsorted[4], Point sorted[4]) {
	// 1.calculate for C (Centroid)
	double Cx = (double)(unsorted[0].x + unsorted[1].x + unsorted[2].x + unsorted[3].x) / 4.0;
	double Cy = (double)(unsorted[0].y + unsorted[1].y + unsorted[2].y + unsorted[3].y) / 4.0;

	// 2. calcuate angle for each point
	AnglePoint temp_points[4];
	for (int i = 0; i < 4; i++) {
		// store the point
		temp_points[i].p = unsorted[i];

		// calculate angle
		double dx = unsorted[i].x - Cx;
		double dy = unsorted[i].y - Cy;
		// atan2 returns angle in radians between -pi and pi
		temp_points[i].angle = atan2(dy, dx);
	}

	// 3. sort points by angle using qsort
	qsort(temp_points, 4, sizeof(AnglePoint), compare_angle);

	// 4. store sorted points back to sorted array
	for (int i = 0; i < 4; i++) {
		sorted[i] = temp_points[i].p;
	}
}

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

	return (ABx * ACx + ABy * ACy);
}

bool is_rectangle(Point points[4])
{
	Point p1 = points[0];
	Point p2 = points[1];
	Point p3 = points[2];
	Point p4 = points[3];

	// calculate using dot product

	
	long long dot1 = dot_product(p1, p2, p4);

	
	long long dot2 = dot_product(p2, p1, p3);

	long long dot3 = dot_product(p3, p2, p4);

	
	long long dot4 = dot_product(p4, p3, p1);

	
	return (dot1 == 0 && dot2 == 0 && dot3 == 0 && dot4 == 0);
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

