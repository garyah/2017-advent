#include "stdafx.h"
#include "CppUnitTest.h"

#include "../advent2017/GeneratorDriver.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Advent2017;

namespace advent2017tests
{
    TEST_CLASS(GeneratorDriverTests)
    {
    public:
        TEST_METHOD(SomeTest)
        {
            GeneratorDriver driver();
            //Assert::AreEqual(expected, driver.someMethod());
        }
    };
}
