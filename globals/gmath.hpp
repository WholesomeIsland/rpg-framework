// gmath.hpp - global math functions

#pragma once
#include "../third-party/sfml/include/SFML/System/Vector2.hpp"

// damage calc formula taken from here https://jmargaris.substack.com/p/you-smack-the-rat-for-damage
// graph from that blog post that graphs this equasion vs fire emblem https://www.desmos.com/calculator/r4djk3ewoo
//returns the ammount of damage taken
int dmgCalc(int atk, int def){
    if(atk >= def){
        return atk-(def/2);
    }
    else{
        return atk * (atk/(2*def));
    }

}

float lerp(float a, float b, float f){
    float retval = a + f * (b - a);
    return retval;
}
sf::Vector2f lerp(sf::Vector2f a, sf::Vector2f b, float f){
    return sf::Vector2f(lerp(a.x, b.x, f), lerp(a.y, b.y, f));
}

float smoothstep(float x){
    return x;
}