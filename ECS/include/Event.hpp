#ifndef EVENT_HPP
#define EVENT_HPP

#include "IEvent.hpp"

namespace ecs
{
    using EventTypeId = TypeId;

    template<typename T>
    class Event : public IEvent
    {
        public:
            Event(EventTypeId eventtypeid) 
                : eventtypeid_(eventtypeid) 
            {
            }

            inline EventTypeId GetEventType() const 
            { 
                return eventtypeid_; 
            }

        private:
            EventTypeId eventtypeid_;
    };
}

#endif // EVENT_HPP

