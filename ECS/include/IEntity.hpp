#ifndef I_ENTITY_HPP
#define I_ENTITY_HPP

#include "Defines.hpp"

namespace ecs
{
    class IEntity
    {
        public:
            IEntity() {}
            virtual ~IEntity() {}

            inline EntityId GetEntityId() 
            { 
                return entityid_; 
            }

        private:
            EntityId entityid_;

            friend class EntityManager;
    };
}

#endif // I_ENTITY_HPP
