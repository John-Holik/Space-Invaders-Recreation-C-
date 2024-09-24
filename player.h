// File   : player.h
// Author : John Holik
// Desc   : Header file for player Class
// *********************************************************************************
#ifndef PLAYER_H
#define PLAYER_H


#include <SFML/Graphics.hpp>

class Player{
public:
    Player(float x, float y);
    
    void update();

    void draw(sf::RenderWindow& window);

private:
    // Shape of Player
    sf::Sprite sprite;
    sf::Texture texture;

    // Player left & right movement speed
    float speed;
};




#endif //PLAYER_H