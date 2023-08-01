#include "game/game.h"
#include "player/player.h"
#include "window/graphicDisplay.h"
#include "window/window.h"

using namespace std;

int main(int argc, char *argv[]) {
    Game g; 
    //  Xwindow w; 
    //  GraphicDisplay display{&g, &w}; 
    g.play();
}
