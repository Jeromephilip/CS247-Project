#include "graphicDisplay.h"

GraphicDisplay::GraphicDisplay(Game* game, Xwindow* window) : game{game}, window{window} {
    game->attach(this); 
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                window->fillRectangle(75 * j, i * 75, 75, 75, 0); 
            }
            else {
                window->fillRectangle(75 * j, 75 * i, 75, 75, 3); 
            }
        }
    }
}

void GraphicDisplay::notify() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                window->fillRectangle(75 * j, i * 75, 75, 75, 0); 
            }
            else {
                window->fillRectangle(75 * j, 75 * i, 75, 75, 3); 
            }
            if (game->getBoard().getPiece(j, i) != nullptr) {
                window->drawString(75 * j + 37, 75 * i + 37, string(1, game->getBoard().getPiece(j, i)->getType())); 
            }
        }
    } 
    return; 
}
