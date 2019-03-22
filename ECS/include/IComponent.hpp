#ifndef I_COMPONENT_HPP
#define I_COMPONENT_HPP

#include "Defines.hpp"

namespace ecs
{
    class IComponent
    {
        public:
            IComponent(ComponentId componentid)
                : componentid_(componentid)
            {
            }

            virtual ~IComponent() {}

            inline ComponentId GetComponentId() const
            {
                return componentid_;
            }

        private:
            const ComponentId componentid_;
    };
}

#endif // I_COMPONENT_HPP

