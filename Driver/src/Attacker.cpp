#include "Attacker.hpp"

#include "ECS.hpp"

namespace driver
{
    Attacker::Attacker(std::string name, size_t health, size_t damage)
        : CombatEntity(name, health, 0)
    {
        attack_ = ecs::ECS::Get()->AddComponent<AttackComponent>(this->GetEntityId(), damage);
    }
}