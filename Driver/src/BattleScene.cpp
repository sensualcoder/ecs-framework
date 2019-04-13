#include "BattleScene.hpp"

#include <iostream>

#include "ECS.hpp"

namespace driver
{
    void BattleScene::Init()
    {
        auto defender1 = ecs::ECS::Get()->CreateEntity<CombatEntity>("Defender1", 5, 0);
        auto defender2 = ecs::ECS::Get()->CreateEntity<CombatEntity>("Defender2", 5, 0);
        auto defender3 = ecs::ECS::Get()->CreateEntity<CombatEntity>("Defender3", 5, 1);

        opponents_.push_back(defender1);
        opponents_.push_back(defender2);
        opponents_.push_back(defender3);

        for(auto opponent : opponents_)
        {
            std::cout << "Enemy " << opponent->GetName() << " appears!\n";
        }
    }

    void BattleScene::Start(Attacker* attacker)
    {
        bool battle_end = false,
             battle_fled = false;

        while(!battle_end)
        {
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
                    this->Attack(attacker);
                    
                    if(opponents_.size() == 0)
                    {
                        battle_end = true;
                    }
                    
                    break;
                }
                case 'F':
                case 'f':
                {
                    this->Flee();
                    battle_end = true;
                    battle_fled = true;
                    break;
                }
                default:
                {
                    std::cout << "Invalid input\n";
                    break;
                }
            }
        }

        if(!battle_fled)
        {
            ecs::ECS::Get()->SendEvent<BattleWinEvent>();
        }
    }

    void BattleScene::Attack(Attacker* attacker)
    {
        int target;

        std::cout << "Select a target: ";
        std::cin >> target;

        attacker->Attack()->Attack(target);
    }

    void BattleScene::Flee()
    {
        ecs::ECS::Get()->SendEvent<BattleFleeEvent>();
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
        if(index > opponents_.size() )
        {
            return nullptr;
        }

        return opponents_[index];
    }
}