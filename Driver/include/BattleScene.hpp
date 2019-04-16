#ifndef BATTLE_SCENE_HPP
#define BATTLE_SCENE_HPP

#include <vector>

#include "Attacker.hpp"
#include "CombatEntity.hpp"

namespace driver
{
    class BattleScene
    {
        public:
            void Init();
            void Start(Attacker* attacker);
            void Attack(Attacker* attacker);
            void Flee();
            
            void DisplayOpponents() const;

            CombatEntity* GetOpponent(size_t index);

            template<typename T, typename...ARGS>
            void AddOpponent(ARGS... args)
            {
                auto opponent = ecs::ECS::Get()->CreateEntity<T>(std::forward<ARGS>(args)...);
                opponents_.push_back(opponent);
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

            inline size_t GetTargetCount() const
            {
                return opponents_.size();
            }
        
        private:
            std::vector<Attacker*> opponents_;
    };
}

#endif // BATTLE_SCENE_HPP
