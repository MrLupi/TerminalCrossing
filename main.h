#ifndef TC_MAIN_H_INCLUDED
#define TC_MAIN_H_INCLUDED

#include "renderer.h"
#include "canvas.h"
#include "tcmap.h"

typedef struct __tc_game_data
{
    tcCanvas_t *canvas;
    tcMap_t *map;
} tcGameData_t;

void tcGameSetup( tcGameData_t gameData );
void tcGameLoop( tcGameData_t gameData );
void tcGameClean( tcGameData_t gameData );

#endif //TC_MAIN_H_INCLUDED