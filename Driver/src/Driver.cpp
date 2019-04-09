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

        // Init entities
        auto attacker = ecs->CreateEntity<Attacker>("Attacker", 5, 1); // Attacker, EntityId == 1

        // Execute
        auto battlescene = battlesys->CreateBattleScene();
        battlescene->AddOpponent<CombatEntity>("Defender1", 5);
        battlescene->AddOpponent<CombatEntity>("Defender2", 5);
        battlescene->AddOpponent<CombatEntity>("Defender3", 5);

        for(auto opponent : *battlescene)
        {
            printf("Enemy %s appears! Has %d HP\n", opponent->GetName().c_str(), opponent->GetHealth() );
        }

        while(battlescene->GetTargetCount() > 0)
        {
            attacker->Attack()->Attack(2);
        }
        
        printf("All enemies defeated!\n");
    }
}