#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "ISystem.hpp"

namespace ecs
{
    using SystemTypeId = TypeId;

    template<typename T>
    class System : public ISystem
    {
        public:
            System(SystemId systemid) 
                : ISystem(systemid) 
            {
            }

            static const SystemTypeId SYSTEM_TYPE_ID;
    };
}

#endif // SYSTEM_HPP

