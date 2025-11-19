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
            int x[4] = { 1, 2, 3, 4 };
            int y[4] = { 4, 3, 2, 1 };




        }
    };
}
