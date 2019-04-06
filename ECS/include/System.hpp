#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <typeinfo>

#include "IObserver.hpp"
#include "ISystem.hpp"

namespace ecs
{
    template<typename T>
    class System 
        : public ISystem
    {
        public:
            System() {}

            static const SystemTypeId SYSTEM_TYPE_ID;
    };

    template<typename T>
    const SystemTypeId System<T>::SYSTEM_TYPE_ID { typeid(T).hash_code() };
}

#endif // SYSTEM_HPP

