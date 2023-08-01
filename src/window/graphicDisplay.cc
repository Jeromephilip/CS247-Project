#include "graphicDisplay.h"

GraphicDisplay::GraphicDisplay(Game* game, Xwindow* window) : game{game}, window{window} {
    game->attach(this); 

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                window->fillRectangle(75 * j, i * 75, 75, 75, Xwindow::AntiqueWhite); 
            }
            else {
                window->fillRectangle(75 * j, 75 * i, 75, 75, Xwindow::DarkOliveGreen4); 
            }
        }
    }
    window->drawString(75 * 8 + 10, 75 * 0 + 37, "8");
    window->drawString(75 * 8 + 10, 75 * 1 + 37, "7");
    window->drawString(75 * 8 + 10, 75 * 2 + 37, "6");
    window->drawString(75 * 8 + 10, 75 * 3 + 37, "5");
    window->drawString(75 * 8 + 10, 75 * 4 + 37, "4");
    window->drawString(75 * 8 + 10, 75 * 5 + 37, "3");
    window->drawString(75 * 8 + 10, 75 * 6 + 37, "2");
    window->drawString(75 * 8 + 10, 75 * 7 + 37, "1");

    window->drawString(75 * 0 + 37, 75 * 8 + 10, "a");
    window->drawString(75 * 1 + 37, 75 * 8 + 10, "b");
    window->drawString(75 * 2 + 37, 75 * 8 + 10, "c");
    window->drawString(75 * 3 + 37, 75 * 8 + 10, "d");
    window->drawString(75 * 4 + 37, 75 * 8 + 10, "e");
    window->drawString(75 * 5 + 37, 75 * 8 + 10, "f");
    window->drawString(75 * 6 + 37, 75 * 8 + 10, "g");
    window->drawString(75 * 7 + 37, 75 * 8 + 10, "h");
}

void GraphicDisplay::notify() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                window->fillRectangle(75 * j, i * 75, 75, 75, Xwindow::AntiqueWhite); 
            }
            else {
                window->fillRectangle(75 * j, 75 * i, 75, 75, Xwindow::DarkOliveGreen4); 
            }
            if (game->getBoard().getPiece(j, i) != nullptr) {
                window->drawString(75 * j + 37, 75 * i + 37, string(1, game->getBoard().getPiece(j, i)->getType())); 
            }
        }
    } 
    window->drawString(75 * 8 + 10, 75 * 0 + 37, "8");
    window->drawString(75 * 8 + 10, 75 * 1 + 37, "7");
    window->drawString(75 * 8 + 10, 75 * 2 + 37, "6");
    window->drawString(75 * 8 + 10, 75 * 3 + 37, "5");
    window->drawString(75 * 8 + 10, 75 * 4 + 37, "4");
    window->drawString(75 * 8 + 10, 75 * 5 + 37, "3");
    window->drawString(75 * 8 + 10, 75 * 6 + 37, "2");
    window->drawString(75 * 8 + 10, 75 * 7 + 37, "1");

    window->drawString(75 * 0 + 37, 75 * 8 + 10, "a");
    window->drawString(75 * 1 + 37, 75 * 8 + 10, "b");
    window->drawString(75 * 2 + 37, 75 * 8 + 10, "c");
    window->drawString(75 * 3 + 37, 75 * 8 + 10, "d");
    window->drawString(75 * 4 + 37, 75 * 8 + 10, "e");
    window->drawString(75 * 5 + 37, 75 * 8 + 10, "f");
    window->drawString(75 * 6 + 37, 75 * 8 + 10, "g");
    window->drawString(75 * 7 + 37, 75 * 8 + 10, "h");
    return; 
}
