
/**
 * PolygonCheckerTests.cpp
 *
 * Comprehensive test suite for triangle operations (Issue #1 and Issue #3)
 *
 * Test Coverage:
 * - classifyTriangle: 10 tests (Test 01-10)
 *   - Equilateral: 2 tests
 *   - Isosceles: 3 tests
 *   - Scalene: 2 tests
 *   - Invalid: 3 tests
 *
 * - calculateTriangleAngles: 10 tests (Test 11-20)
 *   - Valid triangles: 6 tests
 *   - Invalid inputs: 4 tests
 *   - Edge cases: 3 tests
 *
 * Total: 20 tests with 100% pass rate
 */

#include "pch.h"
#include "CppUnitTest.h"

// Import C functions from main project
extern "C" char* classifyTriangle(double side1, double side2, double side3);
extern "C" int calculateTriangleAngles(double side1, double side2, double side3,
    double* angle1, double* angle2, double* angle3);

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

        // TEST 11: Right Triangle - should have 90 degree angle
        TEST_METHOD(Test11_RightTriangle_Has90Degree)
        {
            // Arrange
            double side1 = 3.0;
            double side2 = 4.0;
            double side3 = 5.0;
            double angle1, angle2, angle3;

            // Act
            int result = calculateTriangleAngles(side1, side2, side3,
                &angle1, &angle2, &angle3);

            // Assert
            Assert::AreEqual(1, result, L"Should return success");
            Assert::AreEqual(90.0, angle3, 0.1, L"Angle3 should be 90 degrees");
        }

          // TEST 12: Equilateral triangle - all angles 60 degrees
          TEST_METHOD(Test12_Equilateral_AllAngles60)
            {
                // Arrange
                double side1 = 5.0;
                double side2 = 5.0;
                double side3 = 5.0;
                double angle1, angle2, angle3;

                // Act
                int result = calculateTriangleAngles(side1, side2, side3,
                    &angle1, &angle2, &angle3);

                // Assert
                Assert::AreEqual(1, result, L"Should return success");
                Assert::AreEqual(60.0, angle1, 0.1, L"Angle1 should be 60 degrees");
                Assert::AreEqual(60.0, angle2, 0.1, L"Angle2 should be 60 degrees");
                Assert::AreEqual(60.0, angle3, 0.1, L"Angle3 should be 60 degrees");
            }
          
          // TEST 13: Isosceles triangle - sum equals 180
          TEST_METHOD(Test13_Isosceles_AngleSum180)
          {
              // Arrange
              double side1 = 5.0;
              double side2 = 5.0;
              double side3 = 3.0;
              double angle1, angle2, angle3;

              // Act
              int result = calculateTriangleAngles(side1, side2, side3,
                  &angle1, &angle2, &angle3);

              // Assert
              Assert::AreEqual(1, result, L"Should return success");

              // Verify sum of angles equals 180 degrees
              double sum = angle1 + angle2 + angle3;
              Assert::AreEqual(180.0, sum, 0.1, L"Sum of angles should be 180 degrees");
          }

          // TEST 14: Invalid input - zero side
          TEST_METHOD(Test14_Invalid_ZeroSide)
          {
              // Arrange
              double side1 = 0.0;
              double side2 = 5.0;
              double side3 = 5.0;
              double angle1, angle2, angle3;

              // Act
              int result = calculateTriangleAngles(side1, side2, side3,
                  &angle1, &angle2, &angle3);

              // Assert
              Assert::AreEqual(0, result, L"Should return error for zero side");
          }

          // TEST 15: Invalid input - negative side
          TEST_METHOD(Test15_Invalid_NegativeSide)
          {
              // Arrange
              double side1 = -3.0;
              double side2 = 4.0;
              double side3 = 5.0;
              double angle1, angle2, angle3;

              // Act
              int result = calculateTriangleAngles(side1, side2, side3,
                  &angle1, &angle2, &angle3);

              // Assert
              Assert::AreEqual(0, result, L"Should return error for negative side");
          }

          // TEST 16: Invalid - triangle inequality violation
          TEST_METHOD(Test16_Invalid_TriangleInequality)
          {
              // Arrange
              double side1 = 1.0;
              double side2 = 2.0;
              double side3 = 10.0;
              double angle1, angle2, angle3;

              // Act
              int result = calculateTriangleAngles(side1, side2, side3,
                  &angle1, &angle2, &angle3);

              // Assert
              Assert::AreEqual(0, result, L"Should return error for triangle inequality violation");
          }

          // TEST 17: Invalid input - NULL pointer
          TEST_METHOD(Test17_Invalid_NullPointer)
          {
              // Arrange
              double side1 = 3.0;
              double side2 = 4.0;
              double side3 = 5.0;

              // Act
              int result = calculateTriangleAngles(side1, side2, side3,
                  NULL, NULL, NULL);

              // Assert
              Assert::AreEqual(0, result, L"Should return error for NULL pointers");
          }

          // TEST 18: Scalene triangle - all sides different
          TEST_METHOD(Test18_Scalene_AllSidesDifferent)
          {
              // Arrange
              double side1 = 7.0;
              double side2 = 8.0;
              double side3 = 9.0;
              double angle1, angle2, angle3;

              // Act
              int result = calculateTriangleAngles(side1, side2, side3,
                  &angle1, &angle2, &angle3);

              // Assert
              Assert::AreEqual(1, result, L"Should return success");

              // Verify sum equals 180
              double sum = angle1 + angle2 + angle3;
              Assert::AreEqual(180.0, sum, 0.1, L"Sum should be 180 degrees");
          }

          // TEST 19: Large numeric values
          TEST_METHOD(Test19_LargeValues_Equilateral)
          {
              // Arrange
              double side1 = 100.0;
              double side2 = 100.0;
              double side3 = 100.0;
              double angle1, angle2, angle3;

              // Act
              int result = calculateTriangleAngles(side1, side2, side3,
                  &angle1, &angle2, &angle3);

              // Assert
              Assert::AreEqual(1, result, L"Should return success");
              Assert::AreEqual(60.0, angle1, 0.1, L"Angle1 should be 60 degrees");
              Assert::AreEqual(60.0, angle2, 0.1, L"Angle2 should be 60 degrees");
              Assert::AreEqual(60.0, angle3, 0.1, L"Angle3 should be 60 degrees");
          }

          // TEST 20: Floating-point precision
          TEST_METHOD(Test20_FloatingPoint_Precision)
          {
              // Arrange
              double side1 = 3.5;
              double side2 = 4.2;
              double side3 = 5.8;
              double angle1, angle2, angle3;

              // Act
              int result = calculateTriangleAngles(side1, side2, side3,
                  &angle1, &angle2, &angle3);

              // Assert
              Assert::AreEqual(1, result, L"Should return success");

              // Verify sum is approximately 180 (allow floating-point tolerance)
              double sum = angle1 + angle2 + angle3;
              Assert::IsTrue(sum >= 179.9 && sum <= 180.1,
                  L"Sum should be approximately 180 degrees");
          }
    };
}
