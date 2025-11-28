#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>

extern "C" {
#include "../rectangle1.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectangleTests
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestDistance)
        {
            Dot a = { 0.0, 0.0 };
            Dot b = { 3.0, 4.0 };
            double d = distance(a, b);
            Assert::AreEqual(5.0, d, 1e-6);
        }

        TEST_METHOD(TestIsRightAngle)
        {
            Dot A = { 0.0, 0.0 };
            Dot B = { 1.0, 0.0 };
            Dot C = { 1.0, 1.0 };
            bool isRight = isRightAngle(A, B, C);
            Assert::IsTrue(isRight);
        }

        TEST_METHOD(TestRectangleDetection_SimpleRectangle)
        {
            Dot p1 = { 0.0, 0.0 };
            Dot p2 = { 2.0, 0.0 };
            Dot p3 = { 2.0, 1.0 };
            Dot p4 = { 0.0, 1.0 };

            double d12 = distance(p1, p2);
            double d23 = distance(p2, p3);
            double d34 = distance(p3, p4);
            double d41 = distance(p4, p1);

            bool right1 = isRightAngle(p4, p1, p2);
            bool right2 = isRightAngle(p1, p2, p3);
            bool right3 = isRightAngle(p2, p3, p4);
            bool right4 = isRightAngle(p3, p4, p1);

            bool isRectangle =
                right1 && right2 && right3 && right4 &&
                std::fabs(d12 - d34) < 1e-6 &&
                std::fabs(d23 - d41) < 1e-6;

            Assert::IsTrue(isRectangle);

            double perimeter = d12 + d23 + d34 + d41;
            double area = d12 * d23;

            Assert::AreEqual(6.0, perimeter, 1e-6);
            Assert::AreEqual(2.0, area, 1e-6);
        }

        TEST_METHOD(TestRectangleDetection_NotRectangle)
        {
            Dot p1 = { 0.0, 0.0 };
            Dot p2 = { 1.0, 0.0 };
            Dot p3 = { 2.0, 0.5 };
            Dot p4 = { 0.0, 1.0 };

            double d12 = distance(p1, p2);
            double d23 = distance(p2, p3);
            double d34 = distance(p3, p4);
            double d41 = distance(p4, p1);

            bool right1 = isRightAngle(p4, p1, p2);
            bool right2 = isRightAngle(p1, p2, p3);
            bool right3 = isRightAngle(p2, p3, p4);
            bool right4 = isRightAngle(p3, p4, p1);

            bool isRectangle =
                right1 && right2 && right3 && right4 &&
                std::fabs(d12 - d34) < 1e-6 &&
                std::fabs(d23 - d41) < 1e-6;

            Assert::IsFalse(isRectangle);
        }
    };
}