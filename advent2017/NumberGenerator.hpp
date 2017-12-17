namespace Advent2017
{
    class NumberGenerator
    {
    public:
        NumberGenerator(unsigned initialNumber, unsigned factor) :
            m_number(initialNumber), m_factor(factor)
        {
        }

        unsigned getNextNumber()
        {
            uint64_t product = (uint64_t)m_number * m_factor;
            m_number = calculateMaxSigned32BitRemainder(product);
            return m_number;
        }

    private:
        unsigned calculateMaxSigned32BitRemainder(uint64_t value)
        {
            return value % INT_MAX;
        }

        unsigned m_number;
        unsigned m_factor;
    };
}
