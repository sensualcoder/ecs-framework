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
        auto ecs = ecs::ECS::Get();

        // Init systems
        auto battlesys = ecs->AddSystem<BattleSystem>();
        ecs->AddObserver(battlesys);

        // Init entities
        auto attacker = ecs->CreateEntity<Attacker>("Attacker", 5, 1); // Attacker, EntityId == 1

        // Execute
        auto battlescene = battlesys->CreateBattleScene();
        battlescene->Init();

        battlescene->Start(attacker);
    }
}