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
extern "C" void sort_points(Point unsorted[4], Point sorted[4]);
extern "C" long long dot_product(Point pA, Point pB, Point pC);
extern "C" int compare_angle(const void* a, const void* b);
extern "C" typedef struct AnglePoint
{
    Point p;
	double angle;
}AnglePoint;
extern "C" void calculate_area(Point points[4]);


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

            // case 3: Invalid rectangle (rhombus)
            Point rhombus_points[4] = { {0,0}, {10,5}, {20,0}, {10,-5} };
            Assert::IsFalse(is_rectangle(rhombus_points), L"Error: Should not be a valid rectangle");

        }
		// Test for is_rectangle function
        TEST_METHOD(isrectangle)
        {
            // Test case 1: Valid rectangle
            Point rectangle_points[4] = { {0,0}, {10,0}, {10,5}, {0,5} };
            Assert::IsTrue(is_rectangle(rectangle_points), L"Error: Should be a valid rectangle");
            // Test case 2: Invalid rectangle (parallelogram)
            Point parallelogram_points[4] = { {0,0}, {10,0}, {15,5}, {5,5} };
            Assert::IsFalse(is_rectangle(parallelogram_points), L"Error: Should not be a valid rectangle");
            // Test case 3: Valid square
            Point square_points[4] = { {0,0}, {5,0}, {5,5}, {0,5} };
			Assert::IsTrue(is_rectangle(square_points), L"Error: Should be a valid rectangle");
            // Test case 4: Invalid rectangle (Rhombus)
			Point rhombus_points[4] = { {0,0}, {10,5}, {20,0}, {10,-5} };
			Assert::IsFalse(is_rectangle(rhombus_points), L"Error: Should not be a valid rectangle");

        }
		// Test for dot_product function
        TEST_METHOD(dotproduct)
        {
            // case 1. check if it is Orthogonal (the result should be 0) ---
        // vector A = (2, 0), vector B = (0, 3)
            Point pA1 = { 1, 1 }, pB1 = { 3, 1 }, pC1 = { 1, 4 };
            long long result1 = dot_product(pA1, pB1, pC1);
            Assert::AreEqual(0LL, result1, L"T1: Standard Right Angle Test Failed"); // use 0LL to represent long long 0

            // vector A = (2, 1), vector B = (-1, 2) => dotproduct = 0
            Point pA2 = { 0, 0 }, pB2 = { 2, 1 }, pC2 = { -1, 2 };
            long long result2 = dot_product(pA2, pB2, pC2);
            Assert::AreEqual(0LL, result2, L"T2: Slanted Right Angle Test Failed");

            // case 2. test for other kinds of angle  ---
            //  vector A = (3, 0), vector B = (2, 0) => dotproduct = 6
            Point pA3 = { 0, 0 }, pB3 = { 3, 0 }, pC3 = { 2, 0 };
            long long result3 = dot_product(pA3, pB3, pC3);
            Assert::AreEqual(6LL, result3, L"T3: Acute Angle Test Failed");

            // vector A = (-2, 0), vector B = (1, 0) => dotproduct = -2
            Point pA4 = { 0, 0 }, pB4 = { -2, 0 }, pC4 = { 1, 0 };
            long long result4 = dot_product(pA4, pB4, pC4);
            Assert::AreEqual(-2LL, result4, L"T4: Obtuse Angle Test Failed");

            // case 3. avoid leak---
            // vector A = (60000, 0), vector B = (60000, 0) => dotproduct = 3,600,000,000
            Point pA5 = { 0, 0 }, pB5 = { 60000, 0 }, pC5 = { 60000, 0 };
            long long expected_overflow = 3600000000LL;
            long long result5 = dot_product(pA5, pB5, pC5);
            Assert::AreEqual(expected_overflow, result5, L"T5: Overflow Protection Test Failed");
        }
		// compare angle test
        TEST_METHOD(compareangle)
        {
            AnglePoint pt_a = { {0, 0}, 0.5 };
            AnglePoint pt_b = { {0, 0}, 1.0 };
            AnglePoint pt_c = { {0, 0}, 0.5 };
            AnglePoint pt_d = { {0, 0}, -3.0 };
            AnglePoint pt_e = { {0, 0}, 3.0 };

            //case 1: pt_a < pt_b (0.5 < 1.0) -> expect to return -1
            int result1 = compare_angle(&pt_a, &pt_b);
            Assert::AreEqual(-1, result1, L"T1: Smaller angle failed to return -1");

            // case 2: pt_b > pt_a (1.0 > 0.5) -> expect to return  1
            int result2 = compare_angle(&pt_b, &pt_a);
            Assert::AreEqual(1, result2, L"T2: Larger angle failed to return 1");

            // case3: pt_a == pt_c (0.5 == 0.5) -> expect to return 0
            int result3 = compare_angle(&pt_a, &pt_c);
            Assert::AreEqual(0, result3, L"T3: Equal angles failed to return 0");

            // case 4: 
            int result4 = compare_angle(&pt_d, &pt_e);
            Assert::AreEqual(-1, result4, L"T4: Negative angle failed to be treated as smaller");
        }
		// Test for sort_points function
        TEST_METHOD(sortpoints)
        {
            // case 1:¡@basic test
			Point unsorted1[4] = { {1,0}, {0,1}, {-1,0}, {0,-1} };// expected order: (1,0), (0,1), (-1,0), (0,-1)
			Point expected_sorted1[4] = { {0,-1}, {1,0}, {0,1}, {-1,0} }; // expected order
			Point sorted1[4];
			sort_points(unsorted1, sorted1);
            for (int i = 0; i < 4; i++) {
                Assert::AreEqual(expected_sorted1[i].x, sorted1[i].x, L"T1: X coordinate mismatch");
                Assert::AreEqual(expected_sorted1[i].y, sorted1[i].y, L"T1: Y coordinate mismatch");
			}
			// case 2: random order test Cross-Quadrant Unsorted Test
            
            Point unsorted2[4] = {{10, 10}, {10, -10}, {-10, 10},{-10, -10} };

           
            Point expected_sorted2[4] = { {10, -10}, {10, 10}, {-10, 10}, {-10, -10} };

            Point actual_sorted2[4];
            sort_points(unsorted2, actual_sorted2);

            for (int i = 0; i < 4; i++) {
                
                Assert::AreEqual(expected_sorted2[i].x, actual_sorted2[i].x, L"T2: X-coordinate mismatch in sequence.");
                
                Assert::AreEqual(expected_sorted2[i].y, actual_sorted2[i].y, L"T2: Y-coordinate mismatch in sequence.");
            }

		}
        
     
    };
}

