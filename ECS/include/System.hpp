#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "ISystem.hpp"

namespace ecs
{
    template<typename T>
    class System : public ISystem
    {
        public:
            System() {}

            static const SystemTypeId SYSTEM_TYPE_ID;
    };

    template<typename T>
    const SystemTypeId System<T>::SYSTEM_TYPE_ID = 0;
}

#endif // SYSTEM_HPP

