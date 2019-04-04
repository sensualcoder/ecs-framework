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
                return entitymanager_->DestroyEntity<T>(std::forward<ARGS>(args)...);
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
                return componentmanager_->RemoveComponent<T>(std::forward<ARGS>(args)...);
            }

            // System subsystem
            template<typename T, typename... ARGS>
            T* AddSystem(ARGS... args)
            {
                // Create system
                auto sys = systemmanager_->AddSystem<T>(std::forward<ARGS>(args)...);

                // Add system to event handler observers
                eventhandler_->AddObserver(sys);

                return sys;
            }

            template<typename T>
            void RemoveSystem()
            {
                auto sys = systemmanager_->GetSystem<T>();

                eventhandler_->RemoveObserver(sys);

                systemmanager_->RemoveSystem<T>();
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

        private:
            std::unique_ptr<ComponentManager> componentmanager_;
            std::unique_ptr<EntityManager> entitymanager_;
            std::unique_ptr<SystemManager> systemmanager_;
            std::unique_ptr<EventHandler> eventhandler_;
    };
}

#endif // ECS_HPP

