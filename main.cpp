#include <cstdio>
#include <memory>
#include <string>

#include "ECS.hpp"
#include "Event/IEventListener.hpp"

class MessageComponent : public ecs::Component<MessageComponent>
{
    public:
        void SendMessage(const std::string message) const
        {
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

class MessageSystem : public ecs::System<MessageSystem>, protected ecs::event::IEventListener
{
    public:
        void OnSendMessage(const std::string message) const
        {
            printf("%s\n", message.c_str() );
        }
};

int main()
{
    std::unique_ptr<MessageComponent> ctest = std::make_unique<MessageComponent>();
    std::unique_ptr<Messager> etest = std::make_unique<Messager>(ctest.get() );
    std::unique_ptr<MessageSystem> stest = std::make_unique<MessageSystem>();

    ecs::ECS engine;

    std::string message = "Hello, world!";
    etest->Say(message);

    return 0;
}