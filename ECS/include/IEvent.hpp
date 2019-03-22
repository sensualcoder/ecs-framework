#ifndef I_EVENT_HPP
#define I_EVENT_HPP

#include "Defines.hpp"

namespace ecs
{
    struct IEvent
    {
        virtual TypeId GetEventType() const = 0;
    };
}

#endif // I_EVENT_HPP

