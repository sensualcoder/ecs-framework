#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "Event/IObserver.hpp"
#include "ISystem.hpp"

namespace ecs
{
    template<typename T>
    class System : public ISystem
    {
    };
}

#endif // SYSTEM_HPP

