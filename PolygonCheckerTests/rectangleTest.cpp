#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>
extern "C" typedef struct Point
{
    int x;
    int y;
}Point;
extern "C" void getPoints(Point points[4]);
extern "C" double distanceCalculate(Point p1, Point p2);
extern "C" double calculate_perimeter(Point sorted_points[4]);
extern "C" bool is_rectangle(Point points[4]);
void calculate_area(Point points[4]);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

const double TOLERANCE = 1e-6;

namespace rectangletest
{
    TEST_CLASS(rectangletest)
    {
    public:
        // Test for distanceCalculate function
        TEST_METHOD(distanc_Calculate)
        {
            // Test case 1: Distance between (0,0) and (3,4) should be 5
            Point p1 = { 0, 0 };
            Point p2 = { 3, 4 };
            Assert::AreEqual(5.0, distanceCalculate(p1, p2), TOLERANCE, L"Error");

            // Test case 2: Distance between (-1,-1) and (2,3) should be 5
            Point p3 = { -1, -1 };
            Point p4 = { 2, 3 };
            Assert::AreEqual(5.0, distanceCalculate(p3, p4), TOLERANCE, L"Error");

            // Test case 3: Distance between (1,1) and (1,1) should be 0
            Point p5 = { 1, 1 };
            Assert::AreEqual(0.0, distanceCalculate(p5, p5), TOLERANCE, L"The distance should be 0");


        }
        // Test for perimeter calculation
        TEST_METHOD(calculateperimeter)
        {
            // Test case 1: square test
            Point point1[4] = { {0,0}, {10,0}, {10, 10}, {0,10} };
            Assert::AreEqual(40.0, calculate_perimeter(point1), TOLERANCE, L"Error in square perimeter calculation");

            // Test case 2: rectangle test
            Point point2[4] = { {0,0}, {20,0}, {20, 10}, {0,10} };
            Assert::AreEqual(60.0, calculate_perimeter(point2), TOLERANCE, L"Error in rectangle perimeter calculation");

        }
        // Test for is_rectangle

        TEST_METHOD(isrectangle)
        {
            // case 1: valid rectandle
			Point rectangle_points[4] = { {0,0}, {20,0}, {20,10}, {0,10} };
			Assert::IsTrue(is_rectangle(rectangle_points), L"Error: Should be a valid rectangle");

			// case 2: Invalid rectangle (parallelogram)
			Point parallelogram_points[4] = { {0,0}, {20,5}, {25,15}, {5,10} };
			Assert::IsFalse(is_rectangle(parallelogram_points), L"Error: Should not be a valid rectangle");

            // case 3: Invalid rectangle (rhombus)
			Point rhombus_points[4] = { {0,0}, {10,5}, {20,0}, {10,-5} };
			Assert::IsFalse(is_rectangle(rhombus_points), L"Error: Should not be a valid rectangle");
        }
       
    };
}

