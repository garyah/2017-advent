#include "../advent2017/NumberGenerator.hpp"

namespace Advent2017
{
    class GeneratorDriver
    {
    public:
        static unsigned DriveAndReturnNumberOfMatches(
            unsigned generatorAInitial,
            unsigned generatorBInitial,
            unsigned numberOfRunsToMatch)
        {
            unsigned numberOfMatches = 0;
            NumberGenerator aGenerator(generatorAInitial, 16807u);
            NumberGenerator bGenerator(generatorBInitial, 48271u);
            for (unsigned runNumber = 0; runNumber < numberOfRunsToMatch; ++runNumber)
            {
                if ((aGenerator.getNextNumber() & USHRT_MAX)
                    == (bGenerator.getNextNumber() & USHRT_MAX))
                    ++numberOfMatches;
            }
            return numberOfMatches;
        }

    private:
    };
}
