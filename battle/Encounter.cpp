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
            int mod = 0;
            for(int i = 0; i < 4; i++){
                Character* c = this->player.party[i];
                if(c == nullptr){
                    continue;
                }
                mod++;
            }
            target = this->player.party[rand() % mod];
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
void Encounter::draw(sf::RenderWindow& window, float dt, sf::Font* font){
    window.draw(*this->bgSprite);
    int ei = 0;
    for(auto e : this->enemies){
        int enemyX = 200;
        int enemyY = window.getSize().y / 2;
        if(!e->attacking)
            e->sprite->setPosition({(float)enemyX, (float)enemyY});
        if(e->attacking) {
            e->AttackTick(dt);
        }
        window.draw(*e->sprite);
        ei++;
    }
    for(int i = 0; i < 4; i++){
        int charX = window.getSize().x - 200;
        int charY = window.getSize().y - 150 - (i * 50);
        Character* c = this->player.party[i];
        if(c == nullptr) continue;
        c->sprite->setPosition({(float)charX, (float)charY});
        window.draw(*c->sprite);
    }
    // draw UI
    sf::RectangleShape r;
    r.setSize(sf::Vector2f(window.getSize().x - 20, window.getSize().y / 4 - 10));
    r.setPosition(sf::Vector2f(10.f,  window.getSize().y -  window.getSize().y / 4));
    r.setFillColor(sf::Color(0, 0, 255, 127));
    window.draw(r);
    sf::Text battleText(*font);
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