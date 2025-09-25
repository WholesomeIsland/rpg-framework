#include "game.hpp"

Game::Game(){
    slimeEnemyBase = new Enemy("enemy/slime.png", "enemy/slime.ini", 2, sf::Vector2i(14, 0), sf::Vector2i(32, 32));
    slimeEnemyBase->sprite->addAnimation("attack", sf::Vector2i(14, 0), sf::Vector2i(32, 32), sf::Vector2i(0, 0), 15, sf::Vector2i(0, 0));
    slimeEnemyBase->sprite->setAnimation("idle");
    slimeEnemyBase->sprite->animationManager.setAnimationEndingIndex("idle", sf::Vector2i(2, 0));
    slimeEnemyBase->sprite->animationManager.setAnimationFrequency("idle", 1);
    slimeEnemyBase->sprite->scale({-1.0f, 1.0f});
    mainCharacter = new Character("player/player.png", "player/player.ini", sf::Vector2i(3, 0), sf::Vector2i(32, 32));
    mainWorld->currentParty = new Party();
    mainWorld->currentParty->party[0] = mainCharacter;
    mainWorld->LoadMap("backgrounds/test-map.png");
    Encounter* enc = new Encounter("backgrounds/battle-bg.png", *mainWorld->currentParty, std::vector<Enemy*>{slimeEnemyBase});
    mainWorld->startEncounter(enc);
}
void Game::tick(sf::RenderWindow& window, float deltaTime) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)){
        mainWorld->currentEncounter->doTurn();
    }
    window.clear();
    mainWorld->render(window, deltaTime);
    window.display();
}