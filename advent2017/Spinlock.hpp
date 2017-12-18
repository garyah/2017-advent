#include <list>

namespace Advent2017
{
    class Spinlock
    {
    public:
        static unsigned SpinAndReturnValueAfterLastInserted(size_t stepSize)
        {
            std::list<unsigned> buffer;
            buffer.push_back(0);
            size_t currentPosition = 0;
            for (auto valueToInsert = 1u; valueToInsert <= 2017; ++valueToInsert)
            {
                currentPosition += stepSize;
                currentPosition %= buffer.size();
                std::list<unsigned>::iterator iterator = buffer.begin();
                for (size_t count = 0;
                    count < currentPosition && iterator != buffer.end();
                    ++count, ++iterator);
                (void)buffer.insert(iterator, valueToInsert);
                ++currentPosition;
            }
            for (size_t count = 0; count < currentPosition; ++count)
                (void)buffer.pop_front();
            return buffer.front();
        }

    private:
    };
}
