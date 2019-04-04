#ifndef I_SUBJECT_HPP
#define I_SUBJECT_HPP

#include <algorithm>
#include <vector>

#include "IEvent.hpp"
#include "IObserver.hpp"

namespace ecs
{
    class ISubject
    {
        public:
            void AddObserver(IObserver* observer)
            {
                observers_.push_back(observer);
            }

            void RemoveObserver(IObserver* observer)
            {
                auto obs = std::find(observers_.begin(), observers_.end(), observer);

                if(obs != observers_.end() )
                {
                    observers_.erase(obs);
                }
            }

            void RemoveAllObservers()
            {
                observers_.clear();
            }

            void Notify(IEvent* event)
            {
                for(auto obs = observers_.begin(); obs != observers_.end(); obs++)
                {
                    (*obs)->OnNotify(event);
                }
            }

        private:
            std::vector<IObserver*> observers_;
    };
}

#endif // I_SUBJECT_HPP
