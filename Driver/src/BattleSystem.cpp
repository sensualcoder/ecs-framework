#include "BattleSystem.hpp"

#include <iostream>

// Helper functions
namespace driver
{
    auto calc_damage = [](int attack, int defense) -> int { return attack - defense; };
}

// BattleSystem
namespace driver
{
    BattleSystem::BattleSystem()
    {
    }

    BattleScene* BattleSystem::CreateBattleScene()
    {
        if(battlescene_.get() == nullptr)
        {
            battlescene_ = std::make_unique<BattleScene>();
        }

        return battlescene_.get();
    }

    void BattleSystem::DestroyBattleScene()
    {
        battlescene_ = nullptr;
    }

    void BattleSystem::HandleAttackEvent(ecs::IEvent* event)
    {
        auto attack_event = static_cast<AttackEvent*>(event);
        CombatEntity* target = attack_event->target_;

        if(target == nullptr)
        {
            std::cout << "Target doesn't exist, targeting next\n";

            size_t new_target = battlescene_->GetTargetCount() - 1;
            target = battlescene_->GetOpponent(new_target);
        }
        
        std::cout << "Attacker attacks target " 
                << target->GetName()
                << "!\n";

        target->TakeDamage(calc_damage(attack_event->damage_, target->GetDefense() ) );
    }

    void BattleSystem::HandleEntityDieEvent(ecs::IEvent* event)
    {
        auto die_event = static_cast<EntityDieEvent*>(event);

        auto entitytodie = static_cast<CombatEntity*>(die_event->entity_);

        battlescene_->RemoveOpponent(entitytodie);
    }

    void BattleSystem::HandleBattleWinEvent(ecs::IEvent* event)
    {
        std::cout << "All enemies defeated!\n"
                  << "You won!\n";
        
        this->DestroyBattleScene();
    }

    void BattleSystem::HandleBattleLostEvent(ecs::IEvent* event)
    {
        std::cout << "You lost!\n";

        this->DestroyBattleScene();
    }

    void BattleSystem::HandleBattleFleeEvent(ecs::IEvent* event)
    {
        std::cout << "Fled successfully!\n";
        
        this->DestroyBattleScene();
    }

    void BattleSystem::OnNotify(ecs::IEvent* event)
    {
        if(event->GetEventTypeId() == DriverEvent::EVENT_TYPE_ID)
        {
            static_cast<DriverEvent*>(event)->Handle(this);
        }
    }
}
