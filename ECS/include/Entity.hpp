#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <typeinfo>

#include "IEntity.hpp"

namespace ecs
{
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
    
    template<typename T>
    const EntityTypeId Entity<T>::ENTITY_TYPE_ID { typeid(T).hash_code() };
}

#endif // ENTITY_HPP
