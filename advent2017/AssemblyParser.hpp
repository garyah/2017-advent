#include <string>
#include <vector>

namespace Advent2017
{
    class AssemblyParser
    {
    public:
        AssemblyParser() :
            m_program() {}

        void parseInstruction(const char *program)
        {
        }

        void executeProgram()
        {
        }

        unsigned getLastRecoveryValue()
        {
            return 0;
        }

    private:
        std::vector<std::string> m_program;
    };
}
