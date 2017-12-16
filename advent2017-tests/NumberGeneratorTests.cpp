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
        TEST_METHOD(Initial65GeneratesCorrectFirst5)
        {
            NumberGenerator generator(65ul, 16807u);
            Assert::AreEqual(1092455ull, generator.getNextNumber());
            Assert::AreEqual(1181022009ull, generator.getNextNumber());
            Assert::AreEqual(245556042ull, generator.getNextNumber());
            Assert::AreEqual(1744312007ull, generator.getNextNumber());
            Assert::AreEqual(1352636452ull, generator.getNextNumber());
        }

        TEST_METHOD(Initial8921GeneratesCorrectFirst5)
        {
            NumberGenerator generator(8921ul, 48271u);
            Assert::AreEqual(430625591ull, generator.getNextNumber());
            Assert::AreEqual(1233683848ull, generator.getNextNumber());
            Assert::AreEqual(1431495498ull, generator.getNextNumber());
            Assert::AreEqual(137874439ull, generator.getNextNumber());
            Assert::AreEqual(285222916ull, generator.getNextNumber());
        }
    };
}
