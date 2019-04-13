#ifndef ATTACK_COMPONENT_HPP
#define ATTACK_COMPONENT_HPP

#include "Component.hpp"

#include "EventTypes.hpp"

namespace driver
{
    class AttackComponent
    : public ecs::Component<AttackComponent>
    {
        public:
            AttackComponent(size_t damage);

            void Attack(size_t target);

        private:
            size_t damage_;
    };
}

#endif // ATTACK_COMPONENT_HPP
