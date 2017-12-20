#include <string>

namespace Advent2017
{
    class ProgramDancer
    {
    public:
        static void DanceWithNumberOfProgramsAndMoveListAndReturnFinalPositions(
                        size_t numberOfPrograms, const char *moveList, std::string& finalPositions)
        {
            char result[26 + 1] = { 0 };
            char programName = 'a';
            for (size_t i = 0; i < numberOfPrograms && i < _countof(result) - 1; ++i)
                result[i] = programName++;

            char mutableMoveList[80] = { 0 };
            (void)strncpy_s(mutableMoveList, moveList, _countof(mutableMoveList));
            char *context = nullptr;
            auto moveToken = strtok_s(mutableMoveList, " ,", &context);
            while (moveToken != nullptr)
            {
                moveToken = strtok_s(nullptr, " ,", &context);
            }

            finalPositions.clear();
            finalPositions.append(result);
        }

    //private:
    };
}
