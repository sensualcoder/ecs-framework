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
}

#endif // EVENT_TYPES_HPP
