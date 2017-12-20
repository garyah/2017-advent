#include <stdio.h>

#include "../common/InputReader.hpp"
#include "../advent2017/ProgramDancer.hpp"

using namespace Common;
using namespace Advent2017;

int main()
{
    char *line = NULL;
    while ((line = InputReader::ReadLine()) != NULL)
    {
        ProgramDancer generator;
        //generator.expandAndGenerate(line, 272);
        //(void)printf("%s\n", generator.getChecksum());
    }
    return 0;
}
