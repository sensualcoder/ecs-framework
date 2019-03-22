#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "IComponent.hpp"

namespace ecs
{
    using ComponentTypeId = TypeId;

    template<typename T>
    class Component : public IComponent
    {
        public:
            Component(ComponentId componentid) 
                : IComponent(componentid) 
            {
            }

            static const ComponentTypeId COMPONENT_TYPE_ID;
    };
}

#endif // COMPONENT_HPP

