#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "IComponent.hpp"

namespace ecs
{
    template<typename T>
    class Component : public IComponent
    {
    };
}

#endif // COMPONENT_HPP

