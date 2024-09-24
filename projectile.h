#ifndef PROJECTILE.H
#define PROJECTILE.H

#include <SFML/Graphics.hpp>

class Projectile{
public:
    Projectile(float x, float y);

    void update();

    void draw(sf::RenderWindow& window);

    void collision();

private:
    sf::RectangleShape shape;
    float speed;
};


#endif // PROJECTILE.H