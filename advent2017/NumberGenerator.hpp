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
            m_number = calculateMaxSigned32BitRemainder(product);
            return m_number;
        }

    private:

        uint64_t calculateMaxSigned32BitRemainder(uint64_t value)
        {
            auto quotient = value / 2147483647;
            auto rounded = quotient * 2147483647;
            return value - rounded;
        }

        uint64_t m_number;
        unsigned m_factor;
    };
}
