#include "Attacker.hpp"

#include "ECS.hpp"

namespace driver
{
    Attacker::Attacker(std::string name, size_t health, size_t defense, size_t damage)
        : CombatEntity(name, health, defense), damage_(damage)
    {
        attack_ = ecs::ECS::Get()->AddComponent<AttackComponent>(this->GetEntityId() );
    }
}