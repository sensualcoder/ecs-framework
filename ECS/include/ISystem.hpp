#ifndef I_SYSTEM_HPP
#define I_SYSTEM_HPP

#include "Defines.hpp"

namespace ecs
{
    class ISystem
    {
        public:
            ISystem() {}
            virtual ~ISystem() {}

            virtual void Update() {}
    };
}

#endif // I_SYSTEM_HPP

