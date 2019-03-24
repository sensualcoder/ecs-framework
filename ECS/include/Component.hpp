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

    template<typename T>
    const ComponentTypeId Component<T>::COMPONENT_TYPE_ID = 0;
}

#endif // COMPONENT_HPP

