#include "pch.h"
#include "CppUnitTest.h"
extern "C" {
    #include "../rectangle_function/corner.h"   
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace rectangletest
{
    TEST_CLASS(rectangletest)
    {
    public:
        
        TEST_METHOD(testGetcorner)
        {
            int x[4] = { 1, 4, 1, 4 };
            int y[4] = { 1, 4, 4, 1 };
			getCorner(x, y);
            int leftTop = -1;
            int rightTop = -1;
            int leftBottom = -1;
            int rightBottom = -1;
			Assert::AreEqual(1, x[0]);// Left Top Corner
			Assert::AreEqual(4, y[0]);// Left Top Corner
			Assert::AreEqual(4, x[1]);// Right Top Corner
			Assert::AreEqual(4, y[1]);// Right Top Corner

        }
    };
}
