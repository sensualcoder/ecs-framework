#include <cstdio>
#include <memory>
#include <string>

#include "ECS.hpp"

enum EventType
{
    INVALID_EVENT = 0,
    MESSAGE_EVENT
};

enum ComponentType
{
    INVALID_COMPONENT = 0,
    MESSAGE_COMPONENT
};

enum EntityType
{
    INVALID_ENTITY = 0,
    MESSAGER
};

enum SystemType
{
    INVALID_SYSTEM = 0,
    MESSAGE_SYSTEM
};

struct MessageEvent 
    : public ecs::event::Event<MessageEvent>
{
    MessageEvent(std::string message) 
        : message_(message), Event(EventType::MESSAGE_EVENT) {}

    const std::string message_;
};

class MessageComponent 
    : public ecs::Component<MessageComponent>, 
      public ecs::event::ISubject
{
    public:
        MessageComponent() : Component(ComponentType::MESSAGE_COMPONENT) {}

        void SendMessage(const std::string message) const
        {
            std::unique_ptr<MessageEvent> event = std::make_unique<MessageEvent>(message);

            this->Notify(event.get() );
        }
};

class Messager 
    : public ecs::Entity<Messager>
{
    public:
        Messager(MessageComponent* messagecomponent)
            : messagecomponent_(messagecomponent), Entity(EntityType::MESSAGER) {}

        void Say(const std::string message) const
        {
            messagecomponent_->SendMessage(message);
        }

    private:
        MessageComponent* messagecomponent_;
};

class MessageSystem 
    : public ecs::System<MessageSystem>, 
      public ecs::event::IObserver
{
    public:
        MessageSystem() : System(SystemType::MESSAGE_SYSTEM) {}

        void OnNotify(ecs::event::IEvent* event)
        {
            if(event->GetEventType() == EventType::MESSAGE_EVENT)
            {
                printf("%s\n", static_cast<MessageEvent*>(event)->message_.c_str() );
            }
        }
};

int main()
{
    // Init systems
    std::unique_ptr<MessageSystem> stest = std::make_unique<MessageSystem>();

    // Init components
    std::unique_ptr<MessageComponent> ctest = std::make_unique<MessageComponent>();
    ctest->AddObserver(stest.get() );

    // Init entities
    std::unique_ptr<Messager> etest = std::make_unique<Messager>(ctest.get() );

    // Execute
    std::string message = "Hello, world!";
    etest->Say(message);

    return 0;
}
