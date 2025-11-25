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


    };
}