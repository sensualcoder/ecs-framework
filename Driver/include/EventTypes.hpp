#ifndef EVENT_TYPES_HPP
#define EVENT_TYPES_HPP

#include <iostream>

#include "Event.hpp"

#include "CombatEventHandler.hpp"

namespace driver
{
    // Forward declaration
    class CombatEntity;

    struct DriverEvent : public ecs::Event<DriverEvent>
    {
        virtual void Handle(CombatEventHandler* handler) = 0;
    };

    struct AttackEvent : public DriverEvent
    {
        AttackEvent(size_t damage, CombatEntity* target) 
            : damage_(damage), target_(target)
        {}

        const size_t damage_;
        CombatEntity* target_;

        void Handle(CombatEventHandler* handler)
        {
            handler->HandleAttackEvent(this);
        }
    };   

    struct EntityDieEvent : public DriverEvent
    {
        EntityDieEvent(CombatEntity* entity)
            : entity_(entity)
        {}

        CombatEntity* entity_;

        void Handle(CombatEventHandler* handler)
        {
            handler->HandleEntityDieEvent(this);
        }
    };

    struct BattleWinEvent : public DriverEvent
    {
        void Handle(CombatEventHandler* handler)
        {
            handler->HandleBattleWinEvent(this);
        }
    };

    struct BattleLostEvent : public DriverEvent
    {
        void Handle(CombatEventHandler* handler)
        {
            handler->HandleBattleLostEvent(this);
        }
    };

    struct BattleFleeEvent : public DriverEvent
    {
        void Handle(CombatEventHandler* handler)
        {
            handler->HandleBattleFleeEvent(this);
        }
    };
}

#endif // EVENT_TYPES_HPP
