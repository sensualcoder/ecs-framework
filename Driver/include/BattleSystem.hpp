#ifndef BATTLE_SYSTEM_HPP
#define BATTLE_SYSTEM_HPP

#include <algorithm>
#include <cstdio>
#include <memory>
#include <vector>

#include "System.hpp"

#include "CombatEntity.hpp"
#include "EventTypes.hpp"

namespace driver
{
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
}

#endif // BATTLE_SYSTEM_HPP
