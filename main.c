#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "renderer.h"
#include "canvas.h"
#include "tcmap.h"
#include "tile.h"



char *progname;

int main( int argc, char** argv )
{
    progname = argv[0];

    tcGameData_t gameData;

    tcGameSetup( gameData );
    tcGameLoop( gameData );
    tcGameClean( gameData );     

    return EXIT_SUCCESS;
}

void tcGameSetup( tcGameData_t gameData )
{
    tcRendererInit();
    gameData.canvas = tcRendererCreateCanvas();
    tcRendererRenderCanvas( gameData.canvas );

    gameData.map = tcMapCreateMap();

    gameData.store = tcInitializeTileStore();
}

void tcGameLoop( tcGameData_t gameData )
{
    uint8_t quit = 0;
    
    do
    {
        getUserInput();
        handleGameLogic( gameData );
        handleAnimations( gameData );
        drawCanvas( gameData );
        renderCanvas( gameData );
        waitTime();
    } while ( quit == 0 );
}

void tcGameClean( tcGameData_t gameData )
{
    tcDestroyTcCanvas( &(gameData.canvas) );
    tcMapDestroyMap( &( gameData.map ) );
    system("reset");
}

void getUserInput()
{

}

void handleGameLogic( tcGameData_t gameData )
{

}

void handleAnimations( tcGameData_t gameData )
{

}

void drawCanvas( tcGameData_t gameData )
{

}

void renderCanvas( tcGameData_t gameData )
{

}

void waitTime()
{
    
}
