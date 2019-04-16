#ifndef ATTACK_COMPONENT_HPP
#define ATTACK_COMPONENT_HPP

#include "Component.hpp"

#include "CombatEntity.hpp"
#include "EventTypes.hpp"

namespace driver
{
    class AttackComponent : public ecs::Component<AttackComponent>
    {
        public:
            AttackComponent();

            void Attack(size_t damage, CombatEntity* target);
    };
}

#endif // ATTACK_COMPONENT_HPP
