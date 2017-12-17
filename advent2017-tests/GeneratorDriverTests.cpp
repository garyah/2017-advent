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
        TEST_METHOD(InitialBothZeroReturnsNumberOfRuns)
        {
            Assert::AreEqual(40u*1000u*1000u, GeneratorDriver::DriveAndReturnNumberOfMatches(0u, 0u, 40u*1000u*1000u));
        }

        TEST_METHOD(Initial65And8921For5RunsMatchesOnce)
        {
            Assert::AreEqual(1u, GeneratorDriver::DriveAndReturnNumberOfMatches(65u, 8921u, 5u));
        }
    };
}
