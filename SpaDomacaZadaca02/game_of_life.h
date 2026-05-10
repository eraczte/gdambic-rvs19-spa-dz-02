#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <SFML/Graphics.hpp>

class game_of_life {
private:
    static const int REDAKA = 20;
    static const int STUPACA = 40;

    bool grid[REDAKA][STUPACA];
    bool nextGrid[REDAKA][STUPACA];

    bool randomCell();
    int countNeighbors(int r, int c);

public:
    game_of_life();
    void sljedeca_generacija();
    void iscrtaj(sf::RenderWindow& window);
};

#endif
