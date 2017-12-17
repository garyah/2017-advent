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
            NumberGenerator generator(65u, 16807u);
            Assert::AreEqual(1092455u, generator.getNextNumber());
            Assert::AreEqual(1181022009u, generator.getNextNumber());
            Assert::AreEqual(245556042u, generator.getNextNumber());
            Assert::AreEqual(1744312007u, generator.getNextNumber());
            Assert::AreEqual(1352636452u, generator.getNextNumber());
        }

        TEST_METHOD(Initial8921GeneratesCorrectFirst5)
        {
            NumberGenerator generator(8921u, 48271u);
            Assert::AreEqual(430625591u, generator.getNextNumber());
            Assert::AreEqual(1233683848u, generator.getNextNumber());
            Assert::AreEqual(1431495498u, generator.getNextNumber());
            Assert::AreEqual(137874439u, generator.getNextNumber());
            Assert::AreEqual(285222916u, generator.getNextNumber());
        }
    };
}
