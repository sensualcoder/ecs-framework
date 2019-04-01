#ifndef EVENT_HANDLER_HPP
#define EVENT_HANDLER_HPP

#include <memory>

#include "IEvent.hpp"
#include "ISubject.hpp"

namespace ecs
{
    class EventHandler
        : public ISubject
    {
        using Event_Ptr = std::unique_ptr<IEvent>;

        public:
            template<typename T, typename... ARGS>
            void Send(ARGS&&... args)
            {
                Event_Ptr event = Event_Ptr(new T(std::forward<ARGS>(args)...) );

                this->Notify(event.get() );
            }
    };
}

#endif // EVENT_HANDLER_HPP
