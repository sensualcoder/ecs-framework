#include <cstdio>
#include <memory>
#include <string>

#include "ECS.hpp"

struct MessageEvent : public ecs::event::Event<MessageEvent>
{
    MessageEvent(std::string message) : message_(message) {}

    std::string message_;
};

class MessageComponent 
    : public ecs::Component<MessageComponent>, 
      public ecs::event::ISubject<MessageEvent>
{
    public:
        void SendMessage(const std::string message) const
        {
            this->Notify(MessageEvent { message } );
        }
};

class Messager : public ecs::Entity<Messager>
{
    public:
        Messager(MessageComponent* messagecomponent)
            : messagecomponent_(messagecomponent)
        {
        }

        void Say(const std::string message) const
        {
            messagecomponent_->SendMessage(message);
        }

    private:
        MessageComponent* messagecomponent_;
};

class MessageSystem : public ecs::System<MessageSystem>, public ecs::event::IObserver<MessageEvent>
{
    public:
        void OnNotify(const MessageEvent& event) const
        {
            this->OnSendMessage(event.message_);
        }

        void OnSendMessage(const std::string message) const
        {
            printf("%s\n", message.c_str() );
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
    etest->Say("etest says: " + message);

    return 0;
}