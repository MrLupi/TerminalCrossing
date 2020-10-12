#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "renderer.h"
#include "canvas.h"
#include "tcmap.h"


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
}

void tcGameLoop( tcGameData_t gameData )
{

}

void tcGameClean( tcGameData_t gameData )
{
    tcDestroyTcCanvas( &(gameData.canvas) );
    tcMapDestroyMap( &( gameData.map ) );
    system("reset");
}


