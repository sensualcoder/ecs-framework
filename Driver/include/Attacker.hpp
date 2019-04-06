#ifndef ATTACKER_HPP
#define ATTACKER_HPP

#include "ECS.hpp"

#include "AttackComponent.hpp"
#include "CombatEntity.hpp"

namespace driver
{
    class Attacker
    : public CombatEntity
    {
        public:
            Attacker(ecs::EntityId entityid, size_t health, size_t damage)
                : CombatEntity(entityid, health)
            {
                attack_ = ecs::ECS::Get()->AddComponent<AttackComponent>(entityid, damage);
            }

            inline AttackComponent* Attack()
            {
                return attack_;
            }

        protected:
            AttackComponent* attack_;
    };
}

#endif // ATTACKER_HPP
