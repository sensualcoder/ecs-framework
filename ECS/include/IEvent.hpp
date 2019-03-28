#ifndef I_EVENT_HPP
#define I_EVENT_HPP

#include "Defines.hpp"

namespace ecs
{
    class IEvent
    {
        public:
            IEvent(EventTypeId eventtypeid)
                : eventtypeid_(eventtypeid)
            {
            }

            virtual ~IEvent() {}

            inline EventTypeId GetEventTypeId() const
            {
                return eventtypeid_;
            }

        private:
            const EventTypeId eventtypeid_;
    };
}

#endif // I_EVENT_HPP
