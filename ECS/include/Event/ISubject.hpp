#ifndef I_SUBJECT_HPP
#define I_SUBJECT_HPP

#include <vector>

#include "IEvent.hpp"
#include "IObserver.hpp"

namespace ecs::event
{
    class ISubject
    {
        public:
            void AddObserver(IObserver* observer)
            {
                observers_.push_back(observer);
            }

            void Notify(IEvent* event) const
            {
                for(auto obs : observers_)
                {
                    obs->OnNotify(event);
                }
            }

        private:
            std::vector<IObserver*> observers_;
    };
}

#endif // I_SUBJECT_HPP
