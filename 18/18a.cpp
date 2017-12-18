#include <stdio.h>

#include "../common/InputReader.hpp"
//#include "../advent2017/SafeTileCounter.hpp"

using namespace Common;
//using namespace Advent2017;

int main()
{
    char *line = NULL;
    while ((line = InputReader::ReadLine()) != NULL)
    {
        //SafeTileCounter counter;
        //counter.countTiles(line, 40);
        //(void)printf("%u\n", counter.getNumberSafeTiles());
    }
    return 0;
}
