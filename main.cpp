#include <cstdio>
#include <memory>
#include <string>
#include <vector>

#include "ECS.hpp"

struct AttackEvent
    : public ecs::Event<AttackEvent>
{
    AttackEvent(size_t damage, size_t targetindex) 
        : damage_(damage), targetindex_(targetindex)
    {}

    const size_t damage_;
    const size_t targetindex_;
};

class CombatEntity
    : public ecs::Entity<CombatEntity>
{
    public:
        CombatEntity(ecs::EntityId entityid, size_t health) 
            : Entity(entityid), 
                health_(health)
        {}

        inline size_t GetHealth()
        {
            return health_;
        }

        void TakeDamage(size_t damage)
        {
            printf("Defender takes %zu damage!\n", damage);

            health_ -= damage;
        }

    protected:
        size_t health_;
};


class BattleScene
{
    public:
        void AddOpponent(CombatEntity* opponent)
        {
            opponents_.push_back(opponent);
        }

        CombatEntity* GetOpponent(size_t index)
        {
            return opponents_[index];
        }

        void RemoveOpponent(CombatEntity* opponent)
        {
            auto it = std::find(opponents_.begin(), opponents_.end(), opponent);

            if(it != opponents_.end() )
            {
                opponents_.erase(it);
            }
        }

        inline size_t GetTargetCount() const
        {
            return opponents_.size();
        }
    
    private:
        std::vector<CombatEntity*> opponents_;
};

class BattleSystem
    : public ecs::System<BattleSystem>,
        public ecs::IObserver
{
    public:
        BattleSystem() {}

        BattleScene* CreateBattleScene()
        {
            if(battlescene_.get() == nullptr)
            {
                battlescene_ = std::make_unique<BattleScene>();
            }

            return battlescene_.get();
        }

        void DestroyBattleScene()
        {
            battlescene_ = nullptr;
        }

        void OnNotify(ecs::IEvent* event)
        {
            if(event->GetEventTypeId() == AttackEvent::EVENT_TYPE_ID)
            {
                auto attack = static_cast<AttackEvent*>(event);

                printf("Attacker attacks target %zu!\n", attack->targetindex_+1);

                if(attack->targetindex_ > battlescene_->GetTargetCount() )
                {
                    battlescene_->GetOpponent(battlescene_->GetTargetCount() -1)->TakeDamage(attack->damage_);
                }
                else
                {
                    battlescene_->GetOpponent(attack->targetindex_)->TakeDamage(attack->damage_);
                }
                
            }
        }

    private:
        std::unique_ptr<BattleScene> battlescene_;
};

class AttackComponent
    : public ecs::Component<AttackComponent>
{
    public:
        AttackComponent(ecs::ComponentId componentid, size_t damage)
            : Component(componentid),   
                damage_(damage)
        {}

        void DealDamage(size_t target)
        {
            ecs::ECS::Get()->SendEvent<AttackEvent>(damage_, target);
        }

    private:
        size_t damage_;
};

class Attacker
    : public CombatEntity
{
    public:
        Attacker(ecs::EntityId entityid, size_t health, size_t damage)
            : CombatEntity(entityid, health)
        {
            attack_ = ecs::ECS::Get()->AddComponent<AttackComponent>(entityid, damage);
        }

        inline AttackComponent* Attack()
        {
            return attack_;
        }

    protected:
        AttackComponent* attack_;
};

class Defender
    : public CombatEntity
{
};

int main()
{
    auto ecs = ecs::ECS::Get();

    // Init systems
    auto battlesys = ecs->AddSystem<BattleSystem>();
    ecs->AddObserver(battlesys);

    // Init components

    // Init entities
    auto attacker = ecs->CreateEntity<Attacker>(5, 1); // Attacker, EntityId == 1
    auto defender = ecs->CreateEntity<CombatEntity>(5); // Defender, EtntiyId == 2

    // Execute
    auto battlescene = battlesys->CreateBattleScene();
    battlescene->AddOpponent(defender);

    printf("Defender health: %zu\n", defender->GetHealth() );

    attacker->Attack()->DealDamage(0);

    printf("Defender remaining health: %zu\n", defender->GetHealth() );

    // Cleanup
    ecs->DestroyEntity<Attacker>(1);
    ecs->DestroyEntity<CombatEntity>(2);
    ecs->RemoveComponent<AttackComponent>();
    ecs->RemoveSystem<BattleSystem>();

    return 0;
}
