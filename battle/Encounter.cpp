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
        case EnemyType::Basic:{
            auto t = rand() & 4;
            target = this->player.party[t];
            break;
        }
        case EnemyType::Boss:{
        for(int i = 0; i < 4; i++){
            Character* c = this->player.party[i];
            if(c == nullptr){
                continue;
            }
            if(target == nullptr || c->attack > target->attack){
                target = c;
            }
        }
            break;
        }
        }
        enemytotaketurn->Attack(target);
    }
    else{

    }
    enemyTurn = !enemyTurn;
}
void Encounter::draw(sf::RenderWindow& window){
    window.draw(*this->bgSprite);
    int ei = 0;
    for(auto e : this->enemies){
        int enemyX = 100 + (ei * 100);
        int enemyY = window.getSize().y / 2 - 50;
        e->sprite->sprite.setPosition({(float)enemyX, (float)enemyY});
        window.draw(*e->sprite);
        ei++;
    }
    for(int i = 0; i < 4; i++){
        int charX = window.getSize().x - 200;
        int charY = window.getSize().y - 150 - (i * 50);
        Character* c = this->player.party[i];
        if(c == nullptr) continue;
        c->sprite->sprite.setPosition({(float)charX, (float)charY});
        window.draw(*c->sprite);
    }
    // draw UI

}
Encounter::Encounter(std::filesystem::path bgTexPath, Party& player, std::vector<Enemy*> enemies)
    : bgTex(), bgSprite()
    , enemyTurn(false)
    , player(player)
    , enemies(enemies)
{
    bgTex = new sf::Texture(bgTexPath.string());
    this->bgSprite = new sf::Sprite(*bgTex);
}