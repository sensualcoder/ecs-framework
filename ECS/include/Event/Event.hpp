#ifndef EVENT_HPP
#define EVENT_HPP

#include "IEvent.hpp"

namespace ecs::event
{
    template<typename T>
    class Event : public IEvent
    {
    };
}

#endif // EVENT_HPP

