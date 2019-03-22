#ifndef I_ENTITY_HPP
#define I_ENTITY_HPP

#include "Defines.hpp"

namespace ecs
{
    class IEntity
    {
        public:
            IEntity(EntityId entityid) 
                : entityid_(entityid) 
            {
            }

            virtual ~IEntity() {}

            inline EntityId GetEntityId() 
            { 
                return entityid_; 
            }

        private:
            const EntityId entityid_;
    };
}

#endif // I_ENTITY_HPP

