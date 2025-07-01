//
// Created by Valerie Williams on 6/30/25.
//

#include "Game.h"

Game::Game() {
    // set up the window
    window.create(sf::VideoMode(640, 480), "Simple 2D Game Engine");

    // set up the player
    player.setSize(sf::Vector2f(100.f, 50.f));
    player.setFillColor(sf::Color::Magenta);
    player.setPosition(100.f, 200.f);
}

void Game::run() {
    sf::Clock clock; // start the clock

    while (window.isOpen()) {
        // get delta time (time elapsed since last frame) -> makes things smooth + framerate independent
        sf::Time dt = clock.restart();

        // process input
        processEvents();

        // update game logic
        update(dt);

        // render entities
        render();
    }
}

void Game::processEvents() {
    sf::Event event; // hold each event as we read them

    // check the queue of events
    while (window.pollEvent(event)) {
        // handle window close
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void Game::update(sf::Time dt) {
    float speed = 10.f; // movement speed
    float dx = speed * dt.asSeconds(); // how far to move the frame

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        // move up
        player.move(0.f, -speed * dx);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        player.move(0.f, speed * dx);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        player.move(-speed * dx, 0.f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        player.move(speed * dx, 0.f);
    }
}

void Game::render() {
    // erase everything from the previous frame
    window.clear();

    // draw the new frame
    window.draw(player);

    // display the new frame
    window.display();
}