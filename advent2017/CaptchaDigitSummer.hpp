namespace Advent2017
{
    class CaptchaDigitSummer
    {
    public:
        CaptchaDigitSummer() :
            m_sumRepeated(0)
        {
        }

        void sumRepeating(const char *input)
        {
            sumRepeatingByOffset(input, 1);
        }

        void sumRepeatingOtherHalf(const char *input)
        {
            sumRepeatingByOffset(input, strlen(input) / 2);
        }

        unsigned getSumRepeated()
        {
            return m_sumRepeated;
        }

    private:
        void sumRepeatingByOffset(const char *input, size_t offset)
        {
            auto length = strlen(input);
            for (size_t idx = 0; idx < length; ++idx)
            {
                if (input[idx] == input[(idx + offset) % length])
                    m_sumRepeated += input[idx] - '0';
            }
        }

        unsigned m_sumRepeated;
    };
}
