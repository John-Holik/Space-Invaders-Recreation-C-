// File   : player.cpp
// Author : John Holik
// Desc   : Implementation of the player class
// *********************************************************************************
#include "player.h"
#include <iostream>

// Constructor

Player::Player(float x, float y) : speed(0.1f){
    
    if (!texture.loadFromFile("/home/john/VSCode/Space Invaders/player_icon.png")){
            std::cerr << "Error loading player texture" << std::endl;
        }
        sprite.setTexture(texture); // Set the texture for the sprite
        sprite.setPosition(x, y);   // Set initial position
        sprite.setScale(0.25f, 0.25f);
}

// Methods
// *********************************************************
void Player::update()
{
    // Get the current position of the player
    float playerX = sprite.getPosition().x;
    float playerWidth = sprite.getGlobalBounds().width;

    // Move left if the left arrow is pressed and the player is not at the left edge
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && playerX > 0)
    {
        sprite.move(-speed, 0.f); // Move left
    }
    // Move right if the right arrow is pressed and the player is not at the right edge
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (playerX < (sf::VideoMode::getDesktopMode().width - playerWidth)))
    {
        sprite.move(speed, 0.f); // Move right
    }
}

// Render player icon 
void Player::draw(sf::RenderWindow& window){
    window.draw(sprite);
    // std::cout << "Player Position: (" << shape.getPosition().x << ", " << shape.getPosition().y << ")\n";
}