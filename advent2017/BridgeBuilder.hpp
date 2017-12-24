#include <vector>

namespace Advent2017
{
    class BridgeBuilder
    {
    public:
        BridgeBuilder() : m_maxStrength(0) {}

        void addComponent(const char *componentDescription)
        {
            BridgeComponent component;
            (void)sscanf_s(componentDescription, "%u/%u",
                &component.end1Pins, &component.end2Pins);
            m_components.push_back(component);
        }

        void countBridges()
        {
        }

        unsigned getMaxStrength() { return m_maxStrength; }

    private:
        struct BridgeComponent
        {
            unsigned end1Pins, end2Pins;
        };

        std::vector<BridgeComponent> m_components;
        unsigned m_maxStrength;
    };
}
