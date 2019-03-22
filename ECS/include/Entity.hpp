#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "IEntity.hpp"

namespace ecs
{
    using EntityTypeId = TypeId;

    template<typename T>
    class Entity : public IEntity
    {
        public:
            Entity(EntityId entityid) 
                : IEntity(entityid)
            {
            }

            static const EntityTypeId ENTITY_TYPE_ID;
    };
}

#endif // ENTITY_HPP

