namespace Advent2017
{
    class StreamProcessor
    {
    public:
        static const char *EatGarbage(const char *input)
        {
            if (*input != '<') return input;
            auto isEscaped = false;
            for (++input; *input != 0; ++input)
            {
                if (isEscaped) { isEscaped = false; continue; }
                if (*input == '!') isEscaped = true;
                if (*input == '>') return ++input;
            }
            return input;
        }

        static const char *EatGroup(const char *input, unsigned& numberGroups)
        {
            if (*input != '{') return input;
            for (++input; *input != 0; ++input)
            {
                if (*input == '{') input = EatGroup(input, numberGroups);
                if (*input == '<') input = EatGarbage(input);
                if (*input == '}') { ++numberGroups; return ++input; }
            }
            return input;
        }

        //private:
    };
}
