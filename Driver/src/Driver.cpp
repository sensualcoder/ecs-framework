#include "Driver.hpp"

#include <iostream>

#include "ECS.hpp"

#include "Attacker.hpp"
#include "BattleSystem.hpp"
#include "CombatEntity.hpp"

namespace driver
{
    void Driver::Main()
    {
        // Get ECS instance
        auto ecs = ecs::ECS::Get();

        // Init systems
        auto battlesys = ecs->AddSystem<BattleSystem>();
        ecs->AddObserver(battlesys);

        // Init attacker
        auto attacker = ecs->CreateEntity<Attacker>("Player", 5, 1, 2);

        // Execute
        auto battlescene = battlesys->CreateBattleScene();
        battlescene->Init();

        battlescene->Start(attacker);
    }
}