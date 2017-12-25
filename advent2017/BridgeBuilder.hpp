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
            m_components[end1Pins][end2Pins] = m_components[end2Pins][end1Pins] = component;
        }

        void countBridges()
        {
            for (ComponentSamePinsInventory::iterator it = m_components[0].begin();
                it != m_components[0].end();
                ++it)
            {
                auto& rootComponent = it->second;
                auto rootComponentPins = it->first;

                rootComponent.isUsed = m_components[rootComponentPins][0].isUsed = true;
                ++m_numberOfBridges;

                auto bridgeStrength = rootComponentPins
                    + findNextComponentAndReturnMaxStrength(rootComponentPins);
                if (bridgeStrength > m_maxStrength) m_maxStrength = bridgeStrength;
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

        unsigned findNextComponentAndReturnMaxStrength(unsigned pinsToFind)
        {
            auto nextComponents = m_components[pinsToFind];
            if (nextComponents.size() <= 1) return 0;
            auto maxStrengthToReturn = 0u;

            for (ComponentSamePinsInventory::iterator it = nextComponents.begin();
                it != nextComponents.end();
                ++it)
            {
                auto& nextComponent = it->second;
                if (nextComponent.isUsed) continue;
                auto nextComponentPins = it->first;

                nextComponent.isUsed = m_components[nextComponentPins][pinsToFind].isUsed = true;
                ++m_numberOfBridges;

                auto tentativeMaxStrength = findNextComponentAndReturnMaxStrength(nextComponentPins);
                if (tentativeMaxStrength > maxStrengthToReturn) maxStrengthToReturn = tentativeMaxStrength;
            }
            return maxStrengthToReturn;
        }

        ComponentInventory m_components;
        unsigned m_numberOfBridges;
        unsigned m_maxStrength;
    };
}
