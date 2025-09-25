// gmath.hpp - global math functions

#pragma once
#include "../third-party/sfml/include/SFML/System/Vector2.hpp"
#include <cmath>

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

template<typename T>
T lerp(T a, T b, float f){
    return a + f * (b - a);
}

template <typename T>
T clamp(T value, T min, T max){
    if(value < min) return min;
    if(value > max) return max;
    return value;
}


// https://www.desmos.com/calculator/mwg06ncnsf
// https://www.desmos.com/calculator/nlqzeqxrph

sf::Vector2f calculateJumpArc(sf::Vector2f start, sf::Vector2f end, float height, float t){
    // parabolic jump arc calculation
    // t is a value from 0 to 1 representing the progress of the jump
    sf::Vector2f mid = (start + end) / 2.0f;
    mid.y = start.y;
    mid.y -= height; // raise the midpoint to create the arc

    // Quadratic Bezier curve formula
    sf::Vector2f p0 = start;
    sf::Vector2f p1 = mid;
    sf::Vector2f p2 = end;

    float u = 1 - t;
    sf::Vector2f point = u * u * p0 + 2 * u * t * p1 + t * t * p2;
    return point;
}
float calcJumpArcSpeed(sf::Vector2f start, sf::Vector2f end, float height, float t){
    sf::Vector2f mid = (start + end) / 2.0f;
    mid.y = start.y;
    mid.y -= height; // raise the midpoint to create the arc

    // Quadratic Bezier curve formula
    sf::Vector2f p0 = start;
    sf::Vector2f p1 = mid;
    sf::Vector2f p2 = end;
    float u = 1 - t;
    //calculate tangent line
    sf::Vector2f tangent = 2 * u * (p1 - p0) + 2 * t * (p2 - p1);
    return std::sqrt(tangent.x * tangent.x + tangent.y * tangent.y);
}
// applies velocity to the linear distance along the jump arc, returns the correct distance along the arc
float distAlongJumpToActualDist(sf::Vector2f start, sf::Vector2f end, float height, float t, float dt, float speed){
    sf::Vector2f mid = (start + end) / 2.0f;
    mid.y = start.y;
    mid.y -= height; // raise the midpoint to create the arc

    // Quadratic Bezier curve formula
    sf::Vector2f p0 = start;
    sf::Vector2f p1 = mid;
    sf::Vector2f p2 = end;
    float u = 1 - t;
    //calculate tangent line
    sf::Vector2f tangent = 2 * u * (p1 - p0) + 2 * t * (p2 - p1);
    float tangentLength = std::sqrt(tangent.x * tangent.x + tangent.y * tangent.y);
    return clamp(t + (speed / tangentLength) * dt, 0.0f, 1.0f);
}