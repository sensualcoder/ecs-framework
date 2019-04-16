#include "AttackComponent.hpp"

#include "ECS.hpp"

namespace driver
{
    AttackComponent::AttackComponent()
    {
    }

    void AttackComponent::Attack(size_t damage, CombatEntity* target)
    {
        ecs::ECS::Get()->SendEvent<AttackEvent>(damage, target);
    }
}