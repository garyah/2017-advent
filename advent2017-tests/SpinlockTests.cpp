#include "stdafx.h"
#include "CppUnitTest.h"

#include "../advent2017/Spinlock.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Advent2017;

namespace advent2017tests
{
    TEST_CLASS(SpinlockTests)
    {
    public:
        TEST_METHOD(CanCall)
        {
            //SomeClass someObject();
            Assert::AreEqual(638u, Spinlock::SpinAndReturnValueAfterLastInserted(3));
        }
    };
}
