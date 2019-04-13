#ifndef BATTLE_SYSTEM_HPP
#define BATTLE_SYSTEM_HPP

#include <memory>

#include "System.hpp"

#include "BattleScene.hpp"
#include "CombatEntity.hpp"
#include "EventTypes.hpp"

namespace driver
{
    class BattleSystem
        : public ecs::System<BattleSystem>,
            public ecs::IObserver
    {
        public:
            BattleSystem();

            BattleScene* CreateBattleScene();

            void DestroyBattleScene();

            void OnNotify(ecs::IEvent* event);

        private:
            std::unique_ptr<BattleScene> battlescene_;
    };
}

#endif // BATTLE_SYSTEM_HPP
