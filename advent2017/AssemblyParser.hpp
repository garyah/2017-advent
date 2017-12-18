#include <string>
#include <vector>

namespace Advent2017
{
    enum AssemblyParserOperation
    {
        Snd,
        Set,
        Add,
        Mul,
        Mod,
        Rcv,
        Jgz
    };

    struct AssemblyParserInstruction
    {
        AssemblyParserOperation operation;
        bool isFirstOperandRegister;
        int firstOperand;
        bool isSecondOperandRegister;
        int secondOperand;
    };

    class AssemblyParser
    {
    public:
        AssemblyParser() :
            m_program(),
            m_soundPlayed(false),
            m_valueRecovered(false)
        {
            for (size_t i = 0; i < _countof(m_registers); ++i)
                m_registers[i] = 0;
        }

        void parseInstruction(const char *line)
        {
            char mutableLine[80] = {0};
            (void)strncpy_s(mutableLine, line, _countof(mutableLine));
            char *context = nullptr;
            auto instructionToken = strtok_s(mutableLine, " \t", &context);
            if (instructionToken != nullptr)
            {
                AssemblyParserInstruction instruction;
                do
                {
                    if (strcmp(instructionToken, "snd") == 0) { instruction.operation = Snd; break; }
                    if (strcmp(instructionToken, "set") == 0) { instruction.operation = Set; break; }
                    if (strcmp(instructionToken, "add") == 0) { instruction.operation = Add; break; }
                    if (strcmp(instructionToken, "mul") == 0) { instruction.operation = Mul; break; }
                    if (strcmp(instructionToken, "mod") == 0) { instruction.operation = Mod; break; }
                    if (strcmp(instructionToken, "rcv") == 0) { instruction.operation = Rcv; break; }
                    if (strcmp(instructionToken, "jgz") == 0) { instruction.operation = Jgz; break; }
                } while (0);

                auto nextToken = strtok_s(nullptr, " \t", &context);
                if (nextToken != nullptr)
                {
                    instruction.isFirstOperandRegister = isalpha(nextToken[0]) ? true : false;
                    instruction.firstOperand = isalpha(nextToken[0]) ? toupper(nextToken[0]) - 'A' : atoi(nextToken);
                }

                nextToken = strtok_s(nullptr, " \t", &context);
                if (nextToken != nullptr)
                {
                    instruction.isSecondOperandRegister = isalpha(nextToken[0]) ? true : false;
                    instruction.secondOperand = isalpha(nextToken[0]) ? toupper(nextToken[0]) - 'A' : atoi(nextToken);
                }

                m_program.push_back(instruction);
            }
        }

        void executeProgram()
        {
            for (size_t programCounter = 0; programCounter < m_program.size(); ++programCounter)
            {
                auto instruction = m_program[programCounter];
                switch (instruction.operation)
                {
                case Snd: m_mostRecentSndValue = firstOperandValue(instruction); m_soundPlayed = true;
                    break;
                case Set: setRegister(instruction, secondOperandValue(instruction));
                    break;
                case Add: setRegister(instruction, firstOperandValue(instruction) + secondOperandValue(instruction));
                    break;
                case Mul: setRegister(instruction, firstOperandValue(instruction) * secondOperandValue(instruction));
                    break;
                case Mod: setRegister(instruction, firstOperandValue(instruction) % secondOperandValue(instruction));
                    break;
                case Rcv:
                    if (m_soundPlayed && firstOperandValue(instruction) != 0)
                        { m_firstRecoveryValue = m_mostRecentSndValue; m_valueRecovered = true; }
                    break;
                case Jgz:
                    break;
                default:
                    break;
                }
            }
        }

        int getFirstRecoveryValue()
        {
            return m_firstRecoveryValue;
        }

    private:
        void setRegister(const AssemblyParserInstruction& instruction, int value)
        {
            if (instruction.isFirstOperandRegister)
                m_registers[instruction.firstOperand] = value;
        }

        int firstOperandValue(const AssemblyParserInstruction& instruction)
        {
            return operandValue(instruction.isFirstOperandRegister, instruction.firstOperand);
        }

        int secondOperandValue(const AssemblyParserInstruction& instruction)
        {
            return operandValue(instruction.isSecondOperandRegister, instruction.secondOperand);
        }

        int operandValue(bool isOperandRegister, int operand)
        {
            return isOperandRegister ? m_registers[operand] : operand;
        }

        std::vector<AssemblyParserInstruction> m_program;
        int m_registers[26];
        bool m_soundPlayed;
        int m_mostRecentSndValue;
        bool m_valueRecovered;
        int m_firstRecoveryValue;
    };
}
