#ifndef I_ENTITY_HPP
#define I_ENTITY_HPP

#include "Defines.hpp"

namespace ecs
{
    class IEntity
    {
        public:
            virtual TypeId GetEntityTypeId() const = 0;
    };
}

#endif // I_ENTITY_HPP

