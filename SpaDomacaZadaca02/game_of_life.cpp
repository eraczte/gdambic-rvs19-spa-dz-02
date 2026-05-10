#include "game_of_life.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <SFML/Graphics.hpp>

game_of_life::game_of_life() {
    srand((unsigned)time(nullptr));

    for (int r = 0; r < REDAKA; r++) {
        for (int c = 0; c < STUPACA; c++) {
            grid[r][c] = randomCell();
        }
    }
}

bool game_of_life::randomCell() {
    return (rand() % 100) < 25; // 25% šanse
}

int game_of_life::countNeighbors(int r, int c) {
    int count = 0;

    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            if (!(dr == 0 && dc == 0)) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr >= 0 && nr < REDAKA && nc >= 0 && nc < STUPACA)
                    if (grid[nr][nc]) count++;
            }
        }
    }

    return count;
}

void game_of_life::sljedeca_generacija() {
    for (int r = 0; r < REDAKA; r++) {
        for (int c = 0; c < STUPACA; c++) {
            int n = countNeighbors(r, c);

            if (grid[r][c]) {
                nextGrid[r][c] = (n == 2 || n == 3);
            }
            else {
                nextGrid[r][c] = (n == 3);
            }
        }
    }

    for (int r = 0; r < REDAKA; r++) {
        for (int c = 0; c < STUPACA; c++) {
            grid[r][c] = nextGrid[r][c];
        }
    }
}

void game_of_life::iscrtaj(sf::RenderWindow& window) {
    float cellW = window.getSize().x / (float)STUPACA;
    float cellH = window.getSize().y / (float)REDAKA;

    sf::RectangleShape cell(sf::Vector2f(cellW - 1, cellH - 1));

    for (int r = 0; r < REDAKA; r++) {
        for (int c = 0; c < STUPACA; c++) {

            float x = c * cellW;
            float y = r * cellH;

            // 1) GLOW efekt samo za žive ćelije
            if (grid[r][c]) {
                sf::CircleShape glow;

                float glowSize = std::max(cellW, cellH) * 1.8f;

                glow.setRadius(glowSize);
                glow.setOrigin(glowSize, glowSize);
                glow.setPosition(x + cellW / 2, y + cellH / 2);

                glow.setFillColor(sf::Color(0, 255, 100, 60));
                window.draw(glow);
            }

            // 2) Ćelija
            cell.setPosition(x, y);

            if (grid[r][c]) {
                cell.setFillColor(sf::Color(0, 255, 100)); // živa ćelija
            }
            else {
                cell.setFillColor(sf::Color(30, 30, 30)); // mrtva ćelija
            }

            window.draw(cell);

            
        }
    }
}