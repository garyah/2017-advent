#include <stdio.h>

#include "../common/InputReader.hpp"
#include "../advent2017/Spinlock.hpp"

using namespace Common;
using namespace Advent2017;

int main()
{
    char *line = NULL;
    while ((line = InputReader::ReadLine()) != NULL)
    {
        (void)printf("%u\n", Spinlock::SpinAndReturnValueAfterFirst(atoi(line)));
    }
    return 0;
}
