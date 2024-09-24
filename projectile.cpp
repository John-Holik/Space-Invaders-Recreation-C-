// File   : projectile.cpp
// Author : John Holik
// Desc   : Implementation of Projectile class
// *********************************************************************************
# include "projectile.h"

// Constructor
// *********************************************************************************
Projectile::Projectile(float x, float y, float width, float height, sf::Color color) : speed(0.5f){
    shape.setSize(sf::Vector2f(width, height));
    shape.setPosition(x, y);
    shape.setFillColor(color);
};

// Methods
// *********************************************************************************
// Update Projectiles Position
void Projectile::update(){
    shape.move(0.f, -speed); // Move the projectile upwards
}

// Get the Projectile's shape
const sf::RectangleShape &Projectile::getShape() const
{
    return shape; // Return a const reference to the shape
}

// Check for collision with another shape
bool Projectile::checkCollision(const sf::FloatRect &otherBounds) const
{
    return shape.getGlobalBounds().intersects(otherBounds); // Check for intersection with the other bounds
}