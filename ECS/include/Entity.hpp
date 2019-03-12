#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "IEntity.hpp"

namespace ecs
{
    template<typename T>
    class Entity : public IEntity
    {
    };
}

#endif // ENTITY_HPP

