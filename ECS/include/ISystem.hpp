#ifndef I_SYSTEM_HPP
#define I_SYSTEM_HPP

#include "Defines.hpp"

namespace ecs
{
    class ISystem
    {
        public:
            virtual TypeId GetSystemTypeId() const = 0;
    };
}

#endif // I_SYSTEM_HPP

