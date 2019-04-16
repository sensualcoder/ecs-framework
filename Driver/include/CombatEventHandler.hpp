#ifndef COMBAT_EVENT_HANDLER_HPP
#define COMBAT_EVENT_HANDLER_HPP

#include "IEvent.hpp"

namespace driver
{
    struct CombatEventHandler
    {
        virtual void HandleAttackEvent(ecs::IEvent* event) {}
        virtual void HandleEntityDieEvent(ecs::IEvent* event) {}
        virtual void HandleBattleWinEvent(ecs::IEvent* event) {}
        virtual void HandleBattleLostEvent(ecs::IEvent* event) {}
        virtual void HandleBattleFleeEvent(ecs::IEvent* event) {}
    };
}

#endif // COMBAT_EVENT_HANDLER_HPP
