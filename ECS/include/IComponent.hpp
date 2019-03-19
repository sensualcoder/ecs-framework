#ifndef I_COMPONENT_HPP
#define I_COMPONENT_HPP

#include "Defines.hpp"

namespace ecs
{
    class IComponent
    {
        public:
            virtual TypeId GetComponentTypeId() const = 0;
    };
}

#endif // I_COMPONENT_HPP

