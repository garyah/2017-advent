#include "stdafx.h"
#include "CppUnitTest.h"

#include "../advent2017/AssemblyParser.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Advent2017;

namespace advent2017tests
{
    TEST_CLASS(AssemblyParserTests)
    {
    public:
        TEST_METHOD(SampleProgramReturnsCorrectLastRecoveryValue)
        {
            AssemblyParser parser;
            parser.parseInstruction("set a 1");
            parser.parseInstruction("add a 2");
            parser.parseInstruction("mul a a");
            parser.parseInstruction("mod a 5");
            parser.parseInstruction("snd a");
            parser.parseInstruction("set a 0");
            parser.parseInstruction("rcv a");
            parser.parseInstruction("jgz a -1");
            parser.parseInstruction("set a 1");
            parser.parseInstruction("jgz a -2");
            parser.executeProgram();
            Assert::AreEqual(4, parser.getFirstRecoveryValue());
        }
    };
}
