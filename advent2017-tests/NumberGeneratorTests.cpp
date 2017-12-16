#include "stdafx.h"
#include "CppUnitTest.h"

#include "../advent2017/NumberGenerator.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Advent2017;

namespace advent2017tests
{
    TEST_CLASS(NumberGeneratorTests)
    {
    public:

        TEST_METHOD(CanConstruct)
        {
            NumberGenerator generator(0, 0);
            // Assert::IsTrue(generator != nullptr);
        }
    };
}
