// File   : projectile.h
// Author : John Holik
// Desc   : Header file for Projectile object class
// *********************************************************************************
#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics.hpp>

class Projectile{
public:
    Projectile(float x, float y, float width, float height, sf::Color color);

    void update();

    const sf::RectangleShape &getShape() const;

    // Collision checking method
    bool checkCollision(const sf::FloatRect &otherBounds) const;

private:
    // Shape of Bullet
    sf::RectangleShape shape;

    // Speed bullet moves upwards on screen
    float speed;
};


#endif // PROJECTILE.H