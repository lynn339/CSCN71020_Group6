#include "pch.h"
#include "CppUnitTest.h"
extern "C" {
    #include "../rectangle_function/corner.h"   
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

const double TOLERANCE = 1e-6;

namespace rectangletest
{
    TEST_CLASS(rectangletest)
    {
    public:
        
        TEST_METHOD(distancCalculate)
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
    };
}

