#ifndef I_OBSERVER_HPP
#define I_OBSERVER_HPP

#include "IEvent.hpp"

namespace ecs::event
{
    class IObserver
    {
        public:
            virtual void OnNotify(IEvent* event) = 0;
    };
}

#endif // I_OBSERVER_HPP
