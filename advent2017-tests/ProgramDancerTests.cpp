#include "stdafx.h"
#include "CppUnitTest.h"

#include "../advent2017/ProgramDancer.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Advent2017;

namespace advent2017tests
{
    TEST_CLASS(ProgramDancerTests)
    {
    public:
        TEST_METHOD(MovesFromSampleReturnsCorrectFinal)
        {
            //ProgramDancer someObject();
            std::string finalPositions;
            ProgramDancer::DanceWithNumberOfProgramsAndMoveListAndReturnFinalPositions(
                5, "s1,x3/4", finalPositions);
            Assert::AreEqual("eabdc", finalPositions.data());
        }
    };
}
