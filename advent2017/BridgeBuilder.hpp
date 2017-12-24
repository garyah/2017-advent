#include <map>
#include <unordered_map>

namespace Advent2017
{
    class BridgeBuilder
    {
    public:
        BridgeBuilder() :
            m_maxStrength(0),
            m_numberOfBridges(0)
        {}

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
            for (ComponentSamePinsInventory::iterator it = m_components[0].begin();
                it != m_components[0].end();
                ++it)
            {
                auto nextComponent = it->second;
                auto nextComponentPins = it->first;

                nextComponent.isUsed = true;
                ++m_numberOfBridges;
                auto bridgeStrength = nextComponentPins;
                if (bridgeStrength > m_maxStrength) m_maxStrength = bridgeStrength;

                auto foundComponent = true;
                while (foundComponent)
                {
                    foundComponent = false;
                    auto nextComponents = m_components[nextComponentPins];
                    for (ComponentSamePinsInventory::iterator it = nextComponents.begin();
                        it != nextComponents.end();
                        ++it)
                    {
                        nextComponent = it->second;
                        if (nextComponent.isUsed) continue;
                        if (!foundComponent) bridgeStrength += nextComponentPins;
                        foundComponent = true;
                        nextComponentPins = it->first;

                        nextComponent.isUsed = true;
                        ++m_numberOfBridges;
                        bridgeStrength += nextComponentPins;
                        if (bridgeStrength > m_maxStrength) m_maxStrength = bridgeStrength;
                        bridgeStrength -= nextComponentPins;
                    }
                }
            }
        }

        unsigned getNumberOfBridges() { return m_numberOfBridges; }
        unsigned getMaxStrength() { return m_maxStrength; }

    private:
        struct BridgeComponent
        {
            bool isUsed;
        };
        typedef std::map<unsigned, BridgeComponent> ComponentSamePinsInventory;
        typedef std::unordered_map<unsigned, ComponentSamePinsInventory> ComponentInventory;

        ComponentInventory m_components;
        unsigned m_numberOfBridges;
        unsigned m_maxStrength;
    };
}
