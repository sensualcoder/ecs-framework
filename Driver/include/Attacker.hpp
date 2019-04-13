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
            Attacker( std::string name, size_t health, size_t damage);

            inline AttackComponent* Attack()
            {
                return attack_ != nullptr ? attack_ : nullptr;
            }

        protected:
            AttackComponent* attack_;
    };
}

#endif // ATTACKER_HPP
