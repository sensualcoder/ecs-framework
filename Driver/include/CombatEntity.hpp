#ifndef COMBAT_ENTITY_HPP
#define COMBAT_ENTITY_HPP

#include <cstdio>
#include <string>

#include "Entity.hpp"

namespace driver
{
    class CombatEntity
    : public ecs::Entity<CombatEntity>
    {
        public:
            CombatEntity(ecs::EntityId entityid, std::string name, int health) 
                : Entity(entityid), 
                    name_(name),
                    health_(health)
            {}

            inline std::string GetName()
            {
                return name_;
            }

            inline int GetHealth()
            {
                return health_;
            }

            void TakeDamage(size_t damage)
            {
                printf("%s takes %zu damage!\n", name_.c_str(), damage);

                health_ -= damage;

                if(health_ <= 0)
                {
                    printf("%s destroyed!\n", name_.c_str() );
                    ecs::ECS::Get()->SendEvent<EntityDieEvent>(this);
                }
            }

        protected:
            std::string name_;
            int health_;
    };
}

#endif // COMBAT_ENTITY_HPP
