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
            for (size_t idx = 0; idx < numberOfPrograms && idx < _countof(result) - 1; ++idx)
                result[idx] = programName++;

            char mutableMoveList[80] = { 0 };
            (void)strncpy_s(mutableMoveList, moveList, _countof(mutableMoveList));
            char *context = nullptr;
            auto moveToken = strtok_s(mutableMoveList, " ,", &context);
            while (moveToken != nullptr)
            {
                if (moveToken[0] == 's') // Spin
                {
                    char newResult[26 + 1] = { 0 };
                    auto numberOfProgramsToMoveToFront = (size_t)atoi(moveToken + 1);
                    auto indexOfFirst = strlen(result) - numberOfProgramsToMoveToFront;
                    size_t dstIdx = 0;
                    for (size_t srcIdx = indexOfFirst; srcIdx < strlen(result); ++srcIdx)
                        newResult[dstIdx++] = result[srcIdx];
                    for (size_t srcIdx = 0; srcIdx < indexOfFirst; ++srcIdx)
                        newResult[dstIdx++] = result[srcIdx];
                    (void)strcpy_s(result, _countof(result) - 1, newResult);
                }
                moveToken = strtok_s(nullptr, " ,", &context);
            }

            finalPositions.clear();
            finalPositions.append(result);
        }

    //private:
    };
}
