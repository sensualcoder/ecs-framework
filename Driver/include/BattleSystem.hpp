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
            template<typename T, typename...ARGS>
            void AddOpponent(ARGS... args)
            {
                auto opponent = ecs::ECS::Get()->CreateEntity<T>(std::forward<ARGS>(args)...);
                opponents_.push_back(opponent);
            }

            CombatEntity* GetOpponent(size_t index)
            {
                if(index > opponents_.size() )
                {
                    return nullptr;
                }

                return opponents_[index];
            }

            template<typename T>
            void RemoveOpponent(T* opponent)
            {
                auto it = std::find(opponents_.begin(), opponents_.end(), opponent);

                if(it != opponents_.end() )
                {
                    opponents_.erase(it);
                    ecs::ECS::Get()->DestroyEntity<T>(opponent->GetEntityId() );
                }
            }

            auto begin()
            {
                return opponents_.begin();
            }

            auto end()
            {
                return opponents_.end();
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

                    if(attack->targetindex_ >= battlescene_->GetTargetCount() )
                    {
                        printf("Target doesn't exist, targeting next\n");
                        battlescene_->GetOpponent(battlescene_->GetTargetCount() - 1)->TakeDamage(attack->damage_);
                    }
                    else
                    {
                        battlescene_->GetOpponent(attack->targetindex_)->TakeDamage(attack->damage_);
                    }
                }
                else if(event->GetEventTypeId() == EntityDieEvent::EVENT_TYPE_ID)
                {
                    auto die = static_cast<EntityDieEvent*>(event);

                    auto entitytodie = static_cast<CombatEntity*>(die->entity_);

                    battlescene_->RemoveOpponent(entitytodie);
                }
            }

        private:
            std::unique_ptr<BattleScene> battlescene_;
    };
}

#endif // BATTLE_SYSTEM_HPP
