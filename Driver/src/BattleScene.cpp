#include "BattleScene.hpp"

#include <iostream>

#include "ECS.hpp"

namespace driver
{
    void BattleScene::Init()
    {
        auto defender1 = ecs::ECS::Get()->CreateEntity<Attacker>("Defender1", 5, 0, 1);
        auto defender2 = ecs::ECS::Get()->CreateEntity<Attacker>("Defender2", 5, 0, 1);
        auto defender3 = ecs::ECS::Get()->CreateEntity<Attacker>("Defender3", 5, 1, 2);

        opponents_.push_back(defender1);
        opponents_.push_back(defender2);
        opponents_.push_back(defender3);

        for(auto opponent : opponents_)
        {
            std::cout << "Enemy " << opponent->GetName() << " appears!\n";
        }
    }

    void BattleScene::Start(Attacker* player)
    {
        bool battle_end = false,
             battle_fled = false,
             battle_lost = false;

        while(!battle_end)
        {
            std::cout << "\n" << player->GetName() << " HP: " << player->GetHealth() << "\n\n";

            this->DisplayOpponents();

            std::cout << "\nSelect an option:\n"
                      << "A: Attack\n"
                      << "F: Flee\n";

            char choice;
            std::cin >> choice;

            switch(choice)
            {
                case 'A':
                case 'a':
                {
                    this->Attack(player);
                    break;
                }
                case 'F':
                case 'f':
                {
                    battle_end = battle_fled = true;
                    break;
                }
                default:
                {
                    std::cout << "Invalid input\n";
                    break;
                }
            }

            if(opponents_.size() == 0)
            {
                battle_end = true;
            }
            else if(!battle_fled && !battle_end)
            {
                for(auto op : opponents_)
                {
                    std::cout << op->GetName() << " attacks!\n";
                    op->Attack(player);

                    if(player->GetHealth() == 0)
                    {
                        battle_lost = battle_end = true;
                        break;
                    }
                }
            }
        }

        if(battle_fled)
        {
            ecs::ECS::Get()->SendEvent<BattleFleeEvent>();
        }
        else if(battle_lost)
        {
            ecs::ECS::Get()->SendEvent<BattleLostEvent>();
        }
        else
        {
            ecs::ECS::Get()->SendEvent<BattleWinEvent>();
        }
    }

    void BattleScene::Attack(Attacker* player)
    {
        int target_index;

        std::cout << "Select a target: ";
        std::cin >> target_index;

        auto target = this->GetOpponent(target_index);

        player->Attack(target);
    }

    void BattleScene::DisplayOpponents() const
    {
        for(size_t i = 0; i < opponents_.size(); i++)
        {
            auto opponent = opponents_[i];

            std::cout << i << ": " << opponent->GetName()
                        << ", HP: " << opponent->GetHealth() << "\n";
        }
    }

    CombatEntity* BattleScene::GetOpponent(size_t index)
    {
        if(index >= opponents_.size() )
        {
            return nullptr;
        }

        return opponents_[index];
    }
}