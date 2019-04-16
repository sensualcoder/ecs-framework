#ifndef ATTACKER_HPP
#define ATTACKER_HPP

#include <string>

#include "AttackComponent.hpp"
#include "CombatEntity.hpp"

namespace driver
{
    class Attacker
    : public CombatEntity
    {
        public:
            Attacker(std::string name, size_t health, size_t defense, size_t damage);

            inline void Attack(CombatEntity* target)
            {
                attack_->Attack(damage_, target);
            }

        protected:
            size_t damage_;
            AttackComponent* attack_;
    };
}

#endif // ATTACKER_HPP
