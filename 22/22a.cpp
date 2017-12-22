#include <stdio.h>

#include "../common/InputReader.hpp"
#include "../advent2017/VirusCarrier.hpp"

using namespace Common;
using namespace Advent2017;

int main()
{
    VirusCarrier carrier;
    char *line = NULL;
    while ((line = InputReader::ReadLine()) != NULL)
    {
        // carrier.addMapRow(line);
    }
    // carrier.spreadVirus();
    //(void)printf("%u\n", carrier.getNumberInfectedBySpread());
    return 0;
}
