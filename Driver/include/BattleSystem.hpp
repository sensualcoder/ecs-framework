#ifndef BATTLE_SYSTEM_HPP
#define BATTLE_SYSTEM_HPP

#include <memory>

#include "IObserver.hpp"
#include "System.hpp"

#include "BattleScene.hpp"
#include "CombatEventHandler.hpp"
#include "CombatEntity.hpp"
#include "EventTypes.hpp"

namespace driver
{
    class BattleSystem : public ecs::System<BattleSystem>, 
        public ecs::IObserver, public CombatEventHandler
    {
        public:
            BattleSystem();

            BattleScene* CreateBattleScene();
            void DestroyBattleScene();

            void HandleAttackEvent(ecs::IEvent* event) override;
            void HandleEntityDieEvent(ecs::IEvent* event) override;
            void HandleBattleWinEvent(ecs::IEvent* event) override;
            void HandleBattleLostEvent(ecs::IEvent* event) override;
            void HandleBattleFleeEvent(ecs::IEvent* event) override;

            void OnNotify(ecs::IEvent* event) override;

        private:
            std::unique_ptr<BattleScene> battlescene_;
    };
}

#endif // BATTLE_SYSTEM_HPP
