#include "CombatEntity.hpp"

#include <iostream>

namespace driver
{
    CombatEntity::CombatEntity(std::string name, int health, int defense) 
        : name_(name), health_(health), defense_(defense)
    {
    }

    void CombatEntity::TakeDamage(size_t damage)
    {
        std::cout << name_ << " takes "<< damage << " damage!\n";

        health_ -= damage;

        if(health_ <= 0)
        {
            std::cout << name_ << " defeated!\n";
            ecs::ECS::Get()->SendEvent<EntityDieEvent>(this);
        }
    }
}