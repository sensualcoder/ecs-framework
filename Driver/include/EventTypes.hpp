#ifndef EVENT_TYPES_HPP
#define EVENT_TYPES_HPP

#include "Event.hpp"

namespace driver
{
    struct AttackEvent
        : public ecs::Event<AttackEvent>
    {
        AttackEvent(size_t damage, size_t targetindex) 
            : damage_(damage), targetindex_(targetindex)
        {}

        const size_t damage_;
        const size_t targetindex_;
    };   

    struct EntityDieEvent
        : public ecs::Event<EntityDieEvent>
    {
        EntityDieEvent(ecs::IEntity* entity)
            : entity_(entity)
        {}

        ecs::IEntity* entity_;
    };
}

#endif // EVENT_TYPES_HPP
