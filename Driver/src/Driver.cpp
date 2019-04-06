#include "Driver.hpp"

#include "ECS.hpp"

#include "Attacker.hpp"
#include "BattleSystem.hpp"

namespace driver
{
    void Driver::Main()
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
        ecs->DestroyEntity<Attacker>(attacker->GetEntityId() );
        ecs->DestroyEntity<CombatEntity>(defender->GetEntityId() );
        ecs->RemoveComponent<AttackComponent>();
        ecs->RemoveSystem<BattleSystem>();
    }
}