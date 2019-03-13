#ifndef I_SUBJECT_HPP
#define I_SUBJECT_HPP

#include <vector>

#include "IEvent.hpp"
#include "IObserver.hpp"

namespace ecs::event
{
    template<typename T>
    class ISubject
    {
        public:
            void AddObserver(IObserver<T>* observer)
            {
                observers_.push_back(observer);
            }

            void Notify(const T& event) const
            {
                for(auto obs : observers_)
                {
                    obs->OnNotify(event);
                }
            }

        private:
            std::vector<IObserver<T>*> observers_;
    };
}

#endif // I_SUBJECT_HPP
