#include <map>
#include <unordered_map>

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
            BridgeComponent component = { false };
            m_components[end1Pins][end2Pins] = component;
            m_components[end2Pins][end1Pins] = component;
        }

        void countBridges()
        {
        }

        unsigned getMaxStrength() { return m_maxStrength; }

    private:
        struct BridgeComponent
        {
            bool isUsed;
        };

        std::unordered_map<unsigned, std::map<unsigned, BridgeComponent>> m_components;
        unsigned m_maxStrength;
    };
}
