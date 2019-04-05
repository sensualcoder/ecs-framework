#ifndef SYSTEM_MANAGER_HPP
#define SYSTEM_MANAGER_HPP

#include <memory>
#include <unordered_map>

#include "ISystem.hpp"

namespace ecs
{
    using System_Ptr = std::unique_ptr<ISystem>;

    class SystemManager
    {
        public:
            template<typename T>
            T* GetSystem()
            {
                auto it = systems_.find(T::SYSTEM_TYPE_ID);

                return it != systems_.end() 
                        ? (T*)it->second.get() 
                        : nullptr;
            }

            template<typename T, typename... ARGS>
            T* AddSystem(ARGS&&... args)
            {
                const SystemTypeId stid = T::SYSTEM_TYPE_ID;

                ISystem* sys = new T(std::forward<ARGS>(args)...);
                systems_[stid] = System_Ptr(sys);

                return static_cast<T*>(sys);
            }

            template<typename T>
            void RemoveSystem()
            {
                auto it = systems_.find(T::SYSTEM_TYPE_ID);

                if(it != systems_.end() )
                {
                    systems_.erase(it);
                }
            }

            void RemoveAllSystems()
            {
                systems_.clear();
            }

        private:
            std::unordered_map<SystemTypeId, System_Ptr> systems_;
    };
}

#endif // SYSTEM_MANAGER_HPP
