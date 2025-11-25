#include "pch.h"
#include "CppUnitTest.h"

// Import C functions from main project
extern "C" {
#include "C:\Users\tksthi\source\repos\lynn339\CSCN71020_Group6\triangleSolver.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolygonCheckerTests
{
    TEST_CLASS(PolygonCheckerTests)
    {
    public:

        // TEST 1: Basic Equilateral triangle
        TEST_METHOD(Test01_Equilateral_Basic)
        {
            // Arrange
            double side1 = 5.0;
            double side2 = 5.0;
            double side3 = 5.0;

            // Act
            char* result = classifyTriangle(side1, side2, side3);

            // Assert
            Assert::AreEqual("Equilateral", result);
        }

        // TEST 2: Isosceles - first two sides equal
        TEST_METHOD(Test02_Isosceles_FirstTwo)
        {
            double side1 = 5.0;
            double side2 = 5.0;
            double side3 = 3.0;

            char* result = classifyTriangle(side1, side2, side3);

            Assert::AreEqual("Isosceles", result);
        }

        // TEST 3: Scalene triangle
        TEST_METHOD(Test03_Scalene)
        {
            double side1 = 3.0;
            double side2 = 4.0;
            double side3 = 5.0;

            char* result = classifyTriangle(side1, side2, side3);

            Assert::AreEqual("Scalene", result);
        }

        // TEST 4: Invalid - zero side
        TEST_METHOD(Test04_Invalid_ZeroSide)
        {
            double side1 = 0.0;
            double side2 = 5.0;
            double side3 = 5.0;

            char* result = classifyTriangle(side1, side2, side3);

            Assert::AreEqual("Not a triangle", result);
        }

        // TEST 5: Invalid - negative side
        TEST_METHOD(Test05_Invalid_NegativeSide)
        {
            double side1 = -3.0;
            double side2 = 4.0;
            double side3 = 5.0;

            char* result = classifyTriangle(side1, side2, side3);

            Assert::AreEqual("Not a triangle", result);
        }

        // TEST 6: Invalid - triangle inequality
        TEST_METHOD(Test06_Invalid_Inequality)
        {
            double side1 = 1.0;
            double side2 = 2.0;
            double side3 = 10.0;

            char* result = classifyTriangle(side1, side2, side3);

            Assert::AreEqual("Not a triangle", result);
        }

        // TEST 7: Equilateral - floating point tolerance
        TEST_METHOD(Test07_Equilateral_Tolerance)
        {
            double side1 = 5.00001;
            double side2 = 5.00002;
            double side3 = 5.00003;

            char* result = classifyTriangle(side1, side2, side3);

            Assert::AreEqual("Equilateral", result);
        }

        // TEST 8: Isosceles - last two sides equal
        TEST_METHOD(Test08_Isosceles_LastTwo)
        {
            double side1 = 3.0;
            double side2 = 5.0;
            double side3 = 5.0;

            char* result = classifyTriangle(side1, side2, side3);

            Assert::AreEqual("Isosceles", result);
        }

        // TEST 9: Isosceles - first and third equal
        TEST_METHOD(Test09_Isosceles_FirstThird)
        {
            double side1 = 5.0;
            double side2 = 3.0;
            double side3 = 5.0;

            char* result = classifyTriangle(side1, side2, side3);

            Assert::AreEqual("Isosceles", result);
        }

        // TEST 10: Scalene - floating point values
        TEST_METHOD(Test10_Scalene_FloatingPoint)
        {
            double side1 = 2.5;
            double side2 = 3.7;
            double side3 = 4.9;

            char* result = classifyTriangle(side1, side2, side3);

            Assert::AreEqual("Scalene", result);
        }
    };
}