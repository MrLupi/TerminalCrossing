#ifndef TC_MAIN_H_INCLUDED
#define TC_MAIN_H_INCLUDED

#include "renderer.h"
#include "canvas.h"
#include "tcmap.h"
#include "tile.h"

typedef struct __tc_game_data
{
    tcCanvas_t *canvas;
    tcMap_t *map;
    tcTileStore_t *store;
} tcGameData_t;

void tcGameSetup( tcGameData_t *gameData );
void tcGameLoop( tcGameData_t gameData );
void tcGameClean( tcGameData_t gameData );
void getUserInput();
void handleGameLogic( tcGameData_t gameData );
void handleAnimations( tcGameData_t gameData );
void drawCanvas( tcGameData_t gameData );
void renderCanvas( tcGameData_t gameData );
void waitTime();
#endif //TC_MAIN_H_INCLUDED