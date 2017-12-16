namespace Advent2017
{
    class NumberGenerator
    {
    public:
        NumberGenerator(uint64_t initialNumber, unsigned factor) :
            m_number(initialNumber), m_factor(factor)
        {
        }

        uint64_t getNextNumber()
        {
            auto product = m_number * m_factor;
            auto quotient = product / 2147483647;
            auto rounded = quotient * 2147483647;
            auto remainder = product - rounded;
            m_number = remainder;
            return m_number;
        }

    private:
        uint64_t m_number;
        unsigned m_factor;
    };
}
