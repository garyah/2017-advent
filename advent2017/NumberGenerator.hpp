namespace Advent2017
{
    class NumberGenerator
    {
    public:
        NumberGenerator(unsigned initial, unsigned factor) :
            m_initial(initial), m_factor(factor)
        {
        }

    private:
        unsigned m_initial;
        unsigned m_factor;
    };
}
