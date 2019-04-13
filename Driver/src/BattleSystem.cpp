#include "BattleSystem.hpp"

#include <iostream>

// Helper functions
namespace driver
{
    int CalcDamage(int attack_rating, int defense_rating)
    {
        return attack_rating - defense_rating;
    }
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

    void BattleSystem::OnNotify(ecs::IEvent* event)
    {
        if(event->GetEventTypeId() == AttackEvent::EVENT_TYPE_ID)
        {
            auto attack = static_cast<AttackEvent*>(event);
            size_t target = attack->targetindex_;

            if(attack->targetindex_ >= battlescene_->GetTargetCount() )
            {
                std::cout << "Target doesn't exist, targeting next\n";

                size_t new_target = battlescene_->GetTargetCount() - 1;
                std::cout << "Attacker attacks target " 
                      << new_target
                      << "!\n";

                target = new_target;
            }
            else
            {
                std::cout << "Attacker attacks target " 
                      << attack->targetindex_
                      << "!\n";
            }
            auto opponent = battlescene_->GetOpponent(target);

            opponent->TakeDamage(CalcDamage(attack->damage_, opponent->GetDefense() ) );
        }
        else if(event->GetEventTypeId() == EntityDieEvent::EVENT_TYPE_ID)
        {
            auto die = static_cast<EntityDieEvent*>(event);

            auto entitytodie = static_cast<CombatEntity*>(die->entity_);

            battlescene_->RemoveOpponent(entitytodie);
        }
        else if(event->GetEventTypeId() == BattleWinEvent::EVENT_TYPE_ID)
        {
            std::cout << "All enemies defeated!\n"
                      << "You won!\n";
            this->DestroyBattleScene();
        }
        else if(event->GetEventTypeId() == BattleFleeEvent::EVENT_TYPE_ID)
        {
            std::cout << "Fled successfully!\n";
            this->DestroyBattleScene();
        }
    }
}
