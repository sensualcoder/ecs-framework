#ifndef SYSTEM_MANAGER_HPP
#define SYSTEM_MANAGER_HPP

#include <memory>
#include <vector>

#include "ISystem.hpp"

namespace ecs
{
    using System_Ptr = std::unique_ptr<ISystem>;

    class SystemManager
    {
        public:
            template<typename T, typename... ARGS>
            T* AddSystem(ARGS&&... args)
            {
                SystemId systemid = this->GetSystemId();

                ISystem* sys = new T(systemid, std::forward<ARGS>(args)...);
                systems_.push_back(System_Ptr(sys) );

                return static_cast<T*>(sys);
            }

            void RemoveAllSystems()
            {
                systems_.clear();
            }

        private:
            SystemId GetSystemId() const
            {
                return systems_.size() + 1;
            }

            std::vector<System_Ptr> systems_;
    };
}

#endif // SYSTEM_MANAGER_HPP
