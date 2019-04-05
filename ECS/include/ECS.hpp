#ifndef ECS_HPP
#define ECS_HPP

#include <memory>

#include "ComponentManager.hpp"
#include "EntityManager.hpp"
#include "SystemManager.hpp"

#include "EventHandler.hpp"

#include "Component.hpp"
#include "Entity.hpp"
#include "Event.hpp"
#include "IObserver.hpp"
#include "ISubject.hpp"
#include "System.hpp"

namespace ecs
{
    class ECS
    {
        public:
            ECS() 
                : componentmanager_(new ComponentManager),
                    entitymanager_(new EntityManager),
                    systemmanager_(new SystemManager),
                    eventhandler_(new EventHandler)
            {
            }

            static ECS* Get()
            {
                static ECS instance;
                return &instance;
            }

            // Entity subsystem
            template<typename T, typename... ARGS>
            T* CreateEntity(ARGS... args)
            {
                return entitymanager_->CreateEntity<T>(std::forward<ARGS>(args)...);
            }

            template<typename T, typename... ARGS>
            void DestroyEntity(ARGS... args)
            {
                entitymanager_->DestroyEntity<T>(std::forward<ARGS>(args)...);
            }

            void DestroyAllEntities()
            {
                entitymanager_->DestroyAllEntities();
            }

            // Component subsystem
            template<typename T, typename... ARGS>
            T* AddComponent(ARGS... args)
            {
                return componentmanager_->AddComponent<T>(std::forward<ARGS>(args)...);
            }

            template<typename T, typename... ARGS>
            T* GetComponent(ARGS... args)
            {
                return componentmanager_->GetComponent<T>(std::forward<ARGS>(args)...);
            }

            template<typename T, typename... ARGS>
            void RemoveComponent(ARGS... args)
            {
                componentmanager_->RemoveComponent<T>(std::forward<ARGS>(args)...);
            }

            void RemoveAllComponents()
            {
                componentmanager_->RemoveAllComponents();
            }

            // System subsystem
            template<typename T, typename... ARGS>
            T* AddSystem(ARGS... args)
            {
                return systemmanager_->AddSystem<T>(std::forward<ARGS>(args)...);
            }

            template<typename T, typename... ARGS>
            T* GetSystem(ARGS... args)
            {
                return systemmanager_->GetSystem<T>(std::forward<ARGS>(args)...);
            }

            template<typename T>
            void RemoveSystem()
            {
                systemmanager_->RemoveSystem<T>();
            }

            void RemoveAllSystems()
            {
                systemmanager_->RemoveAllSystems();
            }

            // EventHandler subsystem
            template<typename T, typename... ARGS>
            void SendEvent(ARGS... args)
            {
                eventhandler_->Send<T>(std::forward<ARGS>(args)...);
            }

            void AddObserver(IObserver* observer)
            {
                eventhandler_->AddObserver(observer);
            }

            void RemoveObserver(IObserver* observer)
            {
                eventhandler_->RemoveObserver(observer);
            }

            void RemoveAllObservers()
            {
                eventhandler_->RemoveAllObservers();
            }

        private:
            std::unique_ptr<ComponentManager> componentmanager_;
            std::unique_ptr<EntityManager> entitymanager_;
            std::unique_ptr<SystemManager> systemmanager_;
            std::unique_ptr<EventHandler> eventhandler_;
    };
}

#endif // ECS_HPP

