#ifndef COMBAT_ENTITY_HPP
#define COMBAT_ENTITY_HPP

#include <string>

#include "ECS.hpp"
#include "Entity.hpp"

#include "EventTypes.hpp"

namespace driver
{
    class CombatEntity : public ecs::Entity<CombatEntity>
    {
        public:
            CombatEntity(std::string name, int health, int defense);

            inline std::string GetName()
            {
                return name_;
            }

            inline int GetHealth()
            {
                return health_;
            }

            inline int GetDefense()
            {
                return defense_;
            }

            void TakeDamage(size_t damage);

        protected:
            std::string name_;
            int health_;
            int defense_;
    };
}

#endif // COMBAT_ENTITY_HPP
