#include "Encounter.hpp"
#include <cstdlib>
void Encounter::doTurn(){
    if (enemyTurn)
    {
        Enemy* enemytotaketurn = nullptr;
        for (auto e : this->enemies)
        {
            if(!enemytotaketurn){
                enemytotaketurn = &e;
            }
            if(!e.doneTurn && e.speed > enemytotaketurn->speed){
                enemytotaketurn = &e;
            }
        }
        Character* target = nullptr;
        //enemy takes its turn
        switch (enemytotaketurn->type)
        {
        case EnemyType::Basic:
            auto t = rand() & 4;
            target = &this->player.party[t];
            break;
        
        case EnemyType::Boss:
            break;
        }
    }
    else{

    }
    enemyTurn = !enemyTurn;
}