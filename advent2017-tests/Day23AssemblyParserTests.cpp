#include "stdafx.h"
#include "CppUnitTest.h"

#include "../advent2017/Day23AssemblyParser.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Advent2017;

namespace advent2017tests
{
    TEST_CLASS(Day23AssemblyParserTests)
    {
    public:
        TEST_METHOD(ProgramWithMulReturnsOneMulInvoked)
        {
            Day23AssemblyParser parser;
            parser.parseInstruction("set 1");
            parser.parseInstruction("set 2");
            parser.parseInstruction("mul p");
            parser.executeProgram();
            Assert::AreEqual(1u, parser.getnumberOfMulsInvoked());
        }
    };
}
