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
    float speed;
};




#endif //PLAYER_H