#ifndef _GRAPHIC_DISPLAY_
#define _GRAPHIC_DISPLAY_

#include "observer.h"
#include "../game/game.h"
#include "window.h"

class Game; 

class GraphicDisplay : Observer {
    Game* game; 
    Xwindow* window; 
    public: 
        GraphicDisplay(Game*, Xwindow*); 
        void notify(); 
}; 

#endif
