#ifndef EVENT_HPP
#define EVENT_HPP

#include <typeinfo>

#include "IEvent.hpp"

namespace ecs
{
    template<typename T>
    class Event : public IEvent
    {
        public:
            Event() 
                : IEvent(EVENT_TYPE_ID) 
            {
            }

            static const EventTypeId EVENT_TYPE_ID;
    };

    template<typename T>
    const EventTypeId Event<T>::EVENT_TYPE_ID { typeid(T).hash_code() };
}

#endif // EVENT_HPP
