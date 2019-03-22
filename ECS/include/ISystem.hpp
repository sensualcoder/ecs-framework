#ifndef I_SYSTEM_HPP
#define I_SYSTEM_HPP

#include "Defines.hpp"

namespace ecs
{
    class ISystem
    {
        public:
            ISystem(SystemId systemid)
                : systemid_(systemid)
            {
            }

            virtual ~ISystem() {}

            inline SystemId GetSystemId()
            {
                return systemid_;
            }

        private:
            const SystemId systemid_;
    };
}

#endif // I_SYSTEM_HPP

