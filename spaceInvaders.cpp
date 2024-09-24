// File   : spaceInvaders.cpp
// Author : John Holik
// Desc   : Recreating the classic Space Invaders game in C++ 
// *********************************************************************************

#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.h"
#include "projectile.h"

void draw(sf::RenderWindow& window);

int main()
{
    // Create Window using SFML Graphics Library
// ***********************************************************************************************************
    // Get the desktop mode for full screen dimensions
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();

    // Create a borderless window that covers the entire screen
    sf::RenderWindow window(desktopMode, "Space Invaders Remix", 
                            sf::Style::Titlebar | sf::Style::Close);

    // Set the window to the top-left corner of the screen
    window.setPosition(sf::Vector2i(0, 0));

    // Player size
    float playerWidth = 150.f;
    float playerHeight = 90.f;
    float padding = 100.f; // Space from the bottom of the window

    // Calculate initial position for the player
    float x = (desktopMode.width / 2) - (playerWidth / 2);
    float y = desktopMode.height - playerHeight - padding;

    // Set player starting location
    Player player(x, y);

    // Vector to hold projectiles
    std::vector<Projectile> projectiles;

    // Projectile parameters
    float projectileWidth = 5.f;
    float projectileHeight = 10.f;
    float projectileSpeed = 5.f;

    // Game Loop
    // ***********************************************************************************************************

    // Run the program as long as the window is open
    while (window.isOpen())
    {
        sf::Event event;
        // Process events
        while (window.pollEvent(event))
        {
            // Close window if the close button is pressed
            if (event.type == sf::Event::Closed)
                window.close();
        }

        player.update();

        // Fire projectile
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            // Create a projectile at the center of the player
            float projectileX = player.getPosition().x + (player.getGlobalBounds().getSize().x / 2) - (projectileWidth / 2);
            float projectileY = player.getPosition().y;
            projectiles.emplace_back(projectileX, projectileY, projectileWidth, projectileHeight, sf::Color::White);
        }

        // Update projectiles
        for (size_t i = 0; i < projectiles.size(); ++i)
        {
            projectiles[i].update(); // Update projectile position

            // Check for collision with an enemy (assuming you have an enemy defined)
            /*if (projectiles[i].checkCollision(enemy.getGlobalBounds()))
            {
                // Handle collision (e.g., remove projectile, reduce enemy health)
                projectiles.erase(projectiles.begin() + i); // Remove projectile on collision
                --i;                                        // Adjust index due to removal
            } */
        }

        // Clear the window with a black color
        window.clear(sf::Color::Black); 

        // Draw your game objects here
        player.draw(window);

        // Draw the projectiles
        for (const auto &projectile : projectiles)
        {
            window.draw(projectile.getShape());
        }
        // Display the contents of the window
        window.display();
    }

    return 0;
}
