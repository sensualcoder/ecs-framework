#ifndef COMBAT_ENTITY_HPP
#define COMBAT_ENTITY_HPP

#include <cstdio>

#include "Entity.hpp"

namespace driver
{
    class CombatEntity
    : public ecs::Entity<CombatEntity>
    {
        public:
            CombatEntity(ecs::EntityId entityid, size_t health) 
                : Entity(entityid), 
                    health_(health)
            {}

            inline size_t GetHealth()
            {
                return health_;
            }

            void TakeDamage(size_t damage)
            {
                printf("Defender takes %zu damage!\n", damage);

                health_ -= damage;
            }

        protected:
            size_t health_;
    };
}

#endif // COMBAT_ENTITY_HPP
