#ifndef I_COMPONENT_HPP
#define I_COMPONENT_HPP

#include "Defines.hpp"

namespace ecs
{
    class IComponent
    {
        public:
            IComponent() {}
            virtual ~IComponent() {}

            inline ComponentId GetComponentId() const
            {
                return componentid_;
            }

        private:
            ComponentId componentid_;

            friend class ComponentManager;
    };
}

#endif // I_COMPONENT_HPP

