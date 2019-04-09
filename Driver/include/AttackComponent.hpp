#ifndef ATTACK_COMPONENT_HPP
#define ATTACK_COMPONENT_HPP

#include "ECS.hpp"
#include "Component.hpp"

#include "EventTypes.hpp"

namespace driver
{
    class AttackComponent
    : public ecs::Component<AttackComponent>
    {
        public:
            AttackComponent(ecs::ComponentId componentid, size_t damage)
                : Component(componentid),   
                    damage_(damage)
            {}

            void Attack(size_t target)
            {
                ecs::ECS::Get()->SendEvent<AttackEvent>(damage_, target);
            }

        private:
            size_t damage_;
    };
}

#endif // ATTACK_COMPONENT_HPP
