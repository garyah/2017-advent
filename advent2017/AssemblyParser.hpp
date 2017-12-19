#include <stdint.h>
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
        int64_t firstOperand;
        bool isSecondOperandRegister;
        int64_t secondOperand;
    };

    class AssemblyParser
    {
    public:
        AssemblyParser() :
            m_program(),
            m_soundPlayed(false),
            m_valueRecovered(false),
            m_numberOfSends(0)
        {
            for (size_t i = 0; i < _countof(m_registers); ++i)
                for (size_t j = 0; j < _countof(m_registers[0]); ++j)
                    m_registers[i][j] = 0;
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
            for (size_t programCounter = 0; programCounter >= 0 && programCounter < m_program.size(); ++programCounter)
            {
                programCounter = executeInstructionReturningProgramCounter(programCounter, m_program[programCounter]);
                if (m_valueRecovered) break;
            }
        }

        void executeProgramV2()
        {
        }

        int64_t getFirstRecoveryValue()
        {
            return m_firstRecoveryValue;
        }

        unsigned getnumberOfSends()
        {
            return m_numberOfSends;
        }

    private:
        size_t executeInstructionReturningProgramCounter(size_t programCounter, const AssemblyParserInstruction& instruction, size_t processId = 0)
        {
            auto firstOperand = firstOperandValue(instruction, processId);
            auto secondOperand = secondOperandValue(instruction, processId);
            switch (instruction.operation)
            {
            case Snd: m_mostRecentSndValue = firstOperand; m_soundPlayed = true;
                logOneOperandExecution("snd", firstOperand);
                break;
            case Set: setRegister(instruction, secondOperand);
                logTwoOperandExecution("set", firstOperand, secondOperand);
                break;
            case Add: setRegister(instruction, firstOperand + secondOperand);
                logTwoOperandExecution("add", firstOperand, secondOperand);
                break;
            case Mul: setRegister(instruction, firstOperand * secondOperand);
                logTwoOperandExecution("mul", firstOperand, secondOperand);
                break;
            case Mod: setRegister(instruction, firstOperand % secondOperand);
                logTwoOperandExecution("mod", firstOperand, secondOperand);
                break;
            case Rcv:
                if (m_soundPlayed && firstOperand != 0)
                {
                    m_firstRecoveryValue = m_mostRecentSndValue; m_valueRecovered = true;
                }
                logOneOperandExecution("rcv", firstOperand);
                break;
            case Jgz:
                if (firstOperand > 0 && (secondOperand < 0 || secondOperand > 1))
                    --programCounter += secondOperand;
                logTwoOperandExecution("jgz", firstOperand, secondOperand);
                break;
            default:
                break;
            }
            return programCounter;
        }

        void logOneOperandExecution(const char *instructionName, int64_t operandValue)
        {
            //(void)printf("%s %lld\n", instructionName, operandValue);
        }

        void logTwoOperandExecution(const char *instructionName, int64_t firstOperandValue, int64_t secondOperandValue)
        {
            //(void)printf("%s %lld %lld\n", instructionName, firstOperandValue, secondOperandValue);
        }

        void setRegister(const AssemblyParserInstruction& instruction, int64_t value, size_t processId = 0)
        {
            if (instruction.isFirstOperandRegister)
                m_registers[instruction.firstOperand][processId] = value;
        }

        int64_t firstOperandValue(const AssemblyParserInstruction& instruction, size_t processId = 0)
        {
            return operandValue(instruction.isFirstOperandRegister, instruction.firstOperand, processId);
        }

        int64_t secondOperandValue(const AssemblyParserInstruction& instruction, size_t processId = 0)
        {
            return operandValue(instruction.isSecondOperandRegister, instruction.secondOperand, processId);
        }

        int64_t operandValue(bool isOperandRegister, int64_t operand, size_t processId)
        {
            return isOperandRegister ? m_registers[operand][processId] : operand;
        }

        std::vector<AssemblyParserInstruction> m_program;
        int64_t m_registers[26][2];
        bool m_soundPlayed;
        int64_t m_mostRecentSndValue;
        bool m_valueRecovered;
        int64_t m_firstRecoveryValue;
        unsigned m_numberOfSends;
    };
}
