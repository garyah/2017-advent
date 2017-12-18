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
                setCurrentPositionAndInsertValue(buffer, stepSize, valueToInsert, currentPosition);
            return valueAtPosition(buffer, currentPosition);
        }

    private:

        static void setCurrentPositionAndInsertValue(std::list<unsigned>& buffer, size_t stepSize,
                                                     unsigned valueToInsert, size_t& currentPosition)
        {
            currentPosition = (currentPosition + stepSize) % buffer.size();
            insertAtPosition(buffer, valueToInsert, currentPosition);
            ++currentPosition;
        }

        static void insertAtPosition(std::list<unsigned>& buffer, unsigned valueToInsert, size_t position)
        {
            std::list<unsigned>::iterator iterator = buffer.begin();
            for (size_t count = 0;
                count < position && iterator != buffer.end();
                ++count, ++iterator);
            (void)buffer.insert(iterator, valueToInsert);
        }

        static unsigned valueAtPosition(std::list<unsigned> buffer, size_t position)
        {
            for (size_t count = 0; count < position; ++count)
                (void)buffer.pop_front();
            return buffer.front();
        }
    };
}
