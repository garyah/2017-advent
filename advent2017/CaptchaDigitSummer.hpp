namespace Advent2017
{
    class CaptchaDigitSummer
    {
    public:
        CaptchaDigitSummer()
            : m_sum(0)
        {
        }

        void sumRepeating(const char *input)
        {
            for (const char *p = input; *p; ++p)
            {
                if (*p == *(p + 1) || *(p + 1) == 0 && *p == *input)
                    m_sum += *p - '0';
            }
        }

        unsigned getSumRepeated()
        {
            return m_sum;
        }

    private:
        unsigned m_sum;
    };
}
