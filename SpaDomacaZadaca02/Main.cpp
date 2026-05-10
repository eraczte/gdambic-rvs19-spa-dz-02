#include <SFML/Graphics.hpp>
#include "game_of_life.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 400), "Game of Life - SFML");

    game_of_life the_game;

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (clock.getElapsedTime().asSeconds() >= 2.0f) {
            the_game.sljedeca_generacija();
            clock.restart();
        }

        window.clear();
        the_game.iscrtaj(window);
        window.display();
    }

    return 0;
}