#include <map>
#include <vector>

namespace Advent2017
{
    class BridgeBuilder
    {
    public:
        BridgeBuilder() : m_maxStrength(0) {}

        void addComponent(const char *componentDescription)
        {
            unsigned end1Pins = 0, end2Pins = 0;
            (void)sscanf_s(componentDescription, "%u/%u", &end1Pins, &end2Pins);
            unsigned endWithMinPins = end1Pins <= end2Pins ? end1Pins : end2Pins;
            unsigned endWithMaxPins = endWithMinPins == end1Pins ? end2Pins : end1Pins;
            m_components[endWithMinPins].push_back(endWithMaxPins);
        }

        void countBridges()
        {
        }

        unsigned getMaxStrength() { return m_maxStrength; }

    private:
        std::map<unsigned, std::vector<unsigned>> m_components;
        unsigned m_maxStrength;
    };
}
