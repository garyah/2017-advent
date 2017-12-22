#include <vector>

namespace Advent2017
{
    class VirusCarrier
    {
    public:
        VirusCarrier()
        {
        }

        void addMapRow(const char *row)
        {
            std::vector<bool> gridRow;
            for (const char *p = row; *p; ++p)
            {
                if (*p == '.') gridRow.push_back(false);
                if (*p == '#') gridRow.push_back(true);
            }
            m_grid.push_back(gridRow);
        }

        size_t getNumberOfGridNodes()
        {
            size_t numberOfGridNodes = 0;
            for (std::vector<std::vector<bool>>::iterator it = m_grid.begin();
                it != m_grid.end();
                ++it)
            {
                numberOfGridNodes += it->size();
            }
            return numberOfGridNodes;
        }

    private:
        std::vector<std::vector<bool>> m_grid;
    };
}
