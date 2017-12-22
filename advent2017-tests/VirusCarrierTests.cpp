#include "stdafx.h"
#include "CppUnitTest.h"

#include "../advent2017/VirusCarrier.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Advent2017;

namespace advent2017tests
{
    TEST_CLASS(VirusCarrierTests)
    {
    public:
        TEST_METHOD(CanReadSampleMap)
        {
            VirusCarrier carrier;
            carrier.addMapRow("..#");
            carrier.addMapRow("#..");
            carrier.addMapRow("...");
            Assert::AreEqual((size_t)9, carrier.getNumberOfGridNodes());
        }
    };
}
