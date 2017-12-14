#define xTEST_DEBUG

#include <stdio.h>

#include "../common/InputReader.hpp"
#include "../advent2016/GridMoveParser.hpp"

using namespace Common;
using namespace Advent2016;

int main()
{
    char *line = NULL;
    while ((line = InputReader::ReadLine()) != NULL)
    {
        GridMoveParser parser;
        parser.parse(line);
        (void)printf("%u\n", parser.getShortestPathDistance());
    }
    return 0;
}
