namespace Advent2017
{
    class StreamProcessor
    {
    public:
        static const char *EatGarbage(const char *input)
        {
            if (*input != '<') return input;
            ++input;
            for (auto isEscaped = false; *input != 0; ++input)
            {
                if (isEscaped) { isEscaped = false; continue; }
                if (*input == '!') isEscaped == true;
                if (*input == '>') return ++input;
            }
            return input;
        }

    //private:
    };
}
