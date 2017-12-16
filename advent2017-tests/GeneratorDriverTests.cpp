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
        TEST_METHOD(CanCall)
        {
            Assert::AreEqual(0u, GeneratorDriver::DriveAndReturnNumberOfMatches(0u, 0u, 0u));
        }
    };
}
