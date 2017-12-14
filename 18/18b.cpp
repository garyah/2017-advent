#include <stdio.h>

#include "../common/InputReader.hpp"
#include "../advent2016/SafeTileCounter.hpp"

using namespace Common;
using namespace Advent2016;

int main()
{
    char *line = NULL;
    while ((line = InputReader::ReadLine()) != NULL)
    {
        SafeTileCounter counter;
        counter.countTiles(line, 400000);
        (void)printf("%u\n", counter.getNumberSafeTiles());
    }
    return 0;
}
