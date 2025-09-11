#include "Encounter.hpp"
#include <cstdlib>
void Encounter::doTurn(){
    if (enemyTurn)
    {
        Enemy* enemytotaketurn = nullptr;
        for (auto e : this->enemies)
        {
            if(!enemytotaketurn){
                enemytotaketurn = e;
            }
            if(!e->doneTurn && e->speed > enemytotaketurn->speed){
                enemytotaketurn = e;
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
        for(int i = 0; i < 4; i++){
            Character* c = &this->player.party[i];
            if(c == nullptr){
                continue;
            }
            if(target == nullptr || c->attack > target->attack){
                target = c;
            }
        }
            break;
        }
        enemytotaketurn->Attack(target);
    }
    else{

    }
    enemyTurn = !enemyTurn;
}
void Encounter::draw(sf::RenderWindow& window){
    window.draw(this->bgSprite);
    for(auto e : this->enemies){
        window.draw(e->sprite);
    }
    for(int i = 0; i < 4; i++){
        Character* c = &this->player.party[i];
        window.draw(c->sprite);
    }
    // draw UI

}
Encounter::Encounter(std::filesystem::path bgTexPath, Party& player, std::vector<Enemy*> enemies)
    : bgTex(), bgSprite(*bgTex)
    , enemyTurn(false)
    , player(player)
    , enemies(enemies)
{
    if(!bgTex->loadFromFile(bgTexPath.string())){
        //failed to load texture
        return;
    }
    this->bgSprite.setTexture(*this->bgTex);
}