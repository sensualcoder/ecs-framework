#include "AttackComponent.hpp"

#include "ECS.hpp"

namespace driver
{
    AttackComponent::AttackComponent(size_t damage)
        : damage_(damage)
    {
    }

    void AttackComponent::Attack(size_t target)
    {
        ecs::ECS::Get()->SendEvent<AttackEvent>(damage_, target);
    }
}