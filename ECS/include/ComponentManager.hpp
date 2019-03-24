#ifndef COMPONENT_MANAGER_HPP
#define COMPONENT_MANAGER_HPP

#include <algorithm>
#include <memory>
#include <unordered_map>
#include <vector>

#include "IComponent.hpp"

namespace ecs
{
    using Component_Ptr = std::unique_ptr<IComponent>;

    class ComponentManager
    {
        public:
            template<typename T>
            T* GetComponent(const EntityId entityid)
            {
                auto it = components_.find(T::COMPONENT_TYPE_ID);

                return it != components_.end() 
                        ? (T*)it->second.get() 
                        : nullptr;
            }

            template<typename T, typename... ARGS>
            T* AddComponent(const EntityId entityid, ARGS&&... args)
            {
                const ComponentTypeId ctid = T::COMPONENT_TYPE_ID;
                auto it = components_.find(ctid);

                if(it != components_.end() )
                {
                    componententitymap_[ctid].push_back(entityid);

                    return (T*)it->second.get();
                }

                const ComponentId componentid = this->GetComponentId();

                IComponent* component = new T(componentid, std::forward<ARGS>(args)...);
                components_[ctid] = Component_Ptr(component);

                componententitymap_[ctid].push_back(entityid);

                return static_cast<T*>(component);
            }

            template<typename T>
            void RemoveComponent()
            {
                const ComponentTypeId ctid = T::COMPONENT_TYPE_ID;
                
                components_.erase(ctid);
                componententitymap_.erase(ctid);
            }

            template<typename T>
            void RemoveComponent(EntityId entityid)
            {
                const ComponentTypeId ctid = T::COMPONENT_TYPE_ID;
                
                auto& vec = componententitymap_[ctid];

                auto it = std::find(vec.begin(), vec.end(), entityid);

                if(it != vec.end() )
                {
                    vec.erase(it);
                }
            }

            void RemoveAllComponents()
            {
                components_.clear();
            }

        private:
            const ComponentId GetComponentId() const
            {
                return components_.size() + 1;
            }

            std::unordered_map<ComponentTypeId, Component_Ptr> components_;
            std::unordered_map<ComponentTypeId, std::vector<EntityId>> componententitymap_;
    };
}

#endif // COMPONENT_MANAGER_HPP
