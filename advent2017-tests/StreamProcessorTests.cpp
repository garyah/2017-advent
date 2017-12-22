#include "stdafx.h"
#include "CppUnitTest.h"

#include "../advent2017/StreamProcessor.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Advent2017;

namespace advent2017tests
{
    TEST_CLASS(StreamProcessorTests)
    {
    public:
        TEST_METHOD(CanEatEmptyGarbage)
        {
            //StreamProcessor someObject();
            Assert::AreEqual("", StreamProcessor::EatGarbage("<>"));
        }

        TEST_METHOD(CanEatRandomGarbage)
        {
            Assert::AreEqual("", StreamProcessor::EatGarbage("<lkjghlig t>"));
        }

        TEST_METHOD(CanEatGarbageWithExtraStartingCharacters)
        {
            Assert::AreEqual("", StreamProcessor::EatGarbage("<<<<>"));
        }

        TEST_METHOD(CanEatGarbageWith111)
        {
            Assert::AreEqual("", StreamProcessor::EatGarbage("<<<<>"));
        }

        TEST_METHOD(CanEatGarbageWith112)
        {
            Assert::AreEqual("", StreamProcessor::EatGarbage("<<<<>"));
        }

        TEST_METHOD(CanEatGarbageWith113)
        {
            Assert::AreEqual("", StreamProcessor::EatGarbage("<<<<>"));
        }
    };
}
