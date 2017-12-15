#include "stdafx.h"
#include "CppUnitTest.h"

#include "../advent2017/CaptchaDigitSummer.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Advent2017;

namespace advent2017tests
{
    TEST_CLASS(CaptchaDigitSummerTests)
    {
    public:

        TEST_METHOD(TestMethod01a1)
        {
            CaptchaDigitSummer summer;
            char input[] = "1122";
            summer.sumRepeating(input);
            auto sumRepeated = summer.getSumRepeated();
            Assert::AreEqual(3u, sumRepeated);
        }

        TEST_METHOD(TestMethod01a2)
        {
            CaptchaDigitSummer summer;
            char input[] = "1111";
            summer.sumRepeating(input);
            auto sumRepeated = summer.getSumRepeated();
            Assert::AreEqual(4u, sumRepeated);
        }

        TEST_METHOD(TestMethod01a3)
        {
            CaptchaDigitSummer summer;
            char input[] = "1234";
            summer.sumRepeating(input);
            auto sumRepeated = summer.getSumRepeated();
            Assert::AreEqual(0u, sumRepeated);
        }

        TEST_METHOD(TestMethod01a4)
        {
            CaptchaDigitSummer summer;
            char input[] = "91212129";
            summer.sumRepeating(input);
            auto sumRepeated = summer.getSumRepeated();
            Assert::AreEqual(9u, sumRepeated);
        }

        TEST_METHOD(TestMethod01b1)
        {
            CaptchaDigitSummer summer;
            char input[] = "1212";
            summer.sumRepeatingOtherHalf(input);
            auto sumRepeated = summer.getSumRepeated();
            Assert::AreEqual(6u, sumRepeated);
        }

        TEST_METHOD(TestMethod01b2)
        {
            CaptchaDigitSummer summer;
            char input[] = "1221";
            summer.sumRepeatingOtherHalf(input);
            auto sumRepeated = summer.getSumRepeated();
            Assert::AreEqual(0u, sumRepeated);
        }

        TEST_METHOD(TestMethod01b3)
        {
            CaptchaDigitSummer summer;
            char input[] = "123425";
            summer.sumRepeatingOtherHalf(input);
            auto sumRepeated = summer.getSumRepeated();
            Assert::AreEqual(4u, sumRepeated);
        }

        TEST_METHOD(TestMethod01b4)
        {
            CaptchaDigitSummer summer;
            char input[] = "123123";
            summer.sumRepeatingOtherHalf(input);
            auto sumRepeated = summer.getSumRepeated();
            Assert::AreEqual(12u, sumRepeated);
        }

        TEST_METHOD(TestMethod01b5)
        {
            CaptchaDigitSummer summer;
            char input[] = "12131415";
            summer.sumRepeatingOtherHalf(input);
            auto sumRepeated = summer.getSumRepeated();
            Assert::AreEqual(4u, sumRepeated);
        }
    };
}
