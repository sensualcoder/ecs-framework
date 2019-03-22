#ifndef COMPONENT_MANAGER_HPP
#define COMPONENT_MANAGER_HPP

#include <memory>
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
                auto component = components_[0].get();

                return static_cast<T*>(component);
            }

            template<typename T, typename... ARGS>
            T* AddComponent(const EntityId entityid, ARGS&&... args)
            {
                ComponentId componentid = this->GetComponentId();

                IComponent* component = new T(componentid, std::forward<ARGS>(args)...);
                components_.push_back(Component_Ptr(component) );

                return static_cast<T*>(component);
            }

            template<typename T>
            void RemoveComponent(EntityId entityid)
            {
            }

            void RemoveAllComponents()
            {
                components_.clear();
            }

        private:
            ComponentId GetComponentId() const
            {
                return components_.size() + 1;
            }

            std::vector<Component_Ptr> components_;
    };
}

#endif // COMPONENT_MANAGER_HPP
