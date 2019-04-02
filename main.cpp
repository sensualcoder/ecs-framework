#include <cstdio>
#include <memory>
#include <string>

#include "ECS.hpp"

enum EventType
{
    INVALID_EVENT = 0,
    MESSAGE_EVENT
};

class MessageEvent 
    : public ecs::Event<MessageEvent>
{
    public:
        MessageEvent(std::string message) 
            : message_(message)
        {
        }

        const std::string message_;
};

class MessageSystem 
    : public ecs::System<MessageSystem>
{
    public:
        MessageSystem() = default;
        MessageSystem(const MessageSystem& rhs) = delete;

        void OnNotify(ecs::IEvent* event)
        {
            if(event->GetEventTypeId() == MessageEvent::EVENT_TYPE_ID)
            {
                printf("%s\n", static_cast<MessageEvent*>(event)->message_.c_str() );
            }
        }

        void Update() {}
};

class MessageComponent 
    : public ecs::Component<MessageComponent>
{
    public:
        MessageComponent(ecs::ComponentId componentid) 
            : Component(componentid) 
        {
        }

        MessageComponent(const MessageComponent& rhs) = delete;

        void SendMessage(const std::string message)
        {
            ecs::ECS::Get()->SendEvent<MessageEvent>(message);
        }
};

class Messager 
    : public ecs::Entity<Messager>
{
    public:
        Messager(ecs::EntityId entityid, std::string name)
            : Entity(entityid),
                name_(name)
                
        {
            messagecomponent_ = ecs::ECS::Get()
                                    ->GetComponentManager()
                                    ->AddComponent<MessageComponent>(this->GetEntityId() );
        }

        Messager(const Messager& rhs) = delete;

        void Say(const std::string message) const
        {
            std::string msg = name_ + " says: " + message;

            messagecomponent_->SendMessage(msg);
        }

    private:
        std::string name_;
        MessageComponent* messagecomponent_;
};

int main()
{
    auto ecs = ecs::ECS::Get();
    auto cm = ecs->GetComponentManager();
    auto em = ecs->GetEntityManager();
    auto sm = ecs->GetSystemManager();

    // Init systems
    auto stest = sm->AddSystem<MessageSystem>();

    // Init entities
    auto etest = em->CreateEntity<Messager>("Tester");
    auto id = etest->GetEntityId();

    // Init components
    auto ctest = cm->GetComponent<MessageComponent>(id);

    // Init observers
    ecs->GetEventHandler()->AddObserver(stest);

    // Execute
    std::string message = "Hello, world!";
    MessageEvent evtest { "MessageSystem says: " + message };
    stest->OnNotify(&evtest);

    ctest->SendMessage("MessageComponent says: " + message);

    etest->Say(message);

    // Cleanup
    em->DestroyEntity<Messager>(id);
    cm->RemoveComponent<MessageComponent>();
    sm->RemoveSystem<MessageSystem>();

    return 0;
}
