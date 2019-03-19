#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "Event/IObserver.hpp"
#include "ISystem.hpp"

namespace ecs
{
    using SystemTypeId = TypeId;

    template<typename T>
    class System : public ISystem
    {
        public:
            System(SystemTypeId systemtypeid) : systemtypeid_(systemtypeid) {}

            inline SystemTypeId GetSystemTypeId() const { return systemtypeid_; }

        private:
            SystemTypeId systemtypeid_;
    };
}

#endif // SYSTEM_HPP

