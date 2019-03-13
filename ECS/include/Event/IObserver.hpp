#ifndef I_OBSERVER_HPP
#define I_OBSERVER_HPP

#include "IEvent.hpp"

namespace ecs::event
{
    template<typename T>
    class IObserver
    {
        public:
            virtual void OnNotify(const T&) const = 0;
    };
}

#endif // I_OBSERVER_HPP
