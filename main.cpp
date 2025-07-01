#include <iostream> // standard header for debugging, printing, etc
#include <SFML/Graphics.hpp> // includes sfml modules related to 2d rendering of graphics

int main() {

    // this is the main drawing surface
    sf::RenderWindow window(
        sf::VideoMode(640, 480), // this is the window size in pixels
        "Hello World"); // this is the title that appears at the top of the window

    while (window.isOpen()) { // this is the main render loop, isOpen checks if the window hasn't been closed by the user
        sf::Event event; // sfml uses event systems to track user input like mouse clicks, key presses, etc
        while (window.pollEvent(event)) { // polling is checking for events!
            if (event.type == sf::Event::Closed) // we want to close the window we created when the user clicks close (i.e. a close event)
                window.close();
        }

        window.clear(sf::Color::Black); // clears the window to a solid color, essential for each frame
        // if we do not clear, then new sprites/drawings/text would stack up on top of each other!
        // here, we basically reset the canvas before painting the new frame (rendering new objects)

        // creating a rectangle, kind of self-explanatory here
        sf::RectangleShape rectangle(sf::Vector2f(200.f, 100.f));
        rectangle.setFillColor(sf::Color::Magenta);
        rectangle.setPosition(100.f, 150.f);

        // actually render the rectangle!
        window.draw(rectangle);

        // display the window!
        window.display();
    }
    return 0;
}