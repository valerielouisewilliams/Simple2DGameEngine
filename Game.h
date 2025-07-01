//
// Created by Valerie Williams on 6/30/25.
//
#include <SFML/Graphics.hpp>

#ifndef GAME_H
#define GAME_H

class Game {
public:
    Game();

    void run();
    void processEvents();
    void update(sf::Time dt);
    void render();

private:
    sf::RenderWindow window;
    sf::Clock clock;
    sf::RectangleShape player; // placeholder rectangle for now as we work on the Entity class
};



#endif //GAME_H
