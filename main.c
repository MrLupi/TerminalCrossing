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

    tcGameSetup( &gameData );
    tcGameLoop( gameData );
    tcGameClean( gameData );     

    return EXIT_SUCCESS;
}

void tcGameSetup( tcGameData_t *gameData )
{
    tcRendererInit();
    gameData->canvas = tcRendererCreateCanvas();
    tcRendererRenderCanvas( gameData->canvas );

    gameData->store = tcInitializeTileStore();

    gameData->map = tcMapCreateMap();

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
    static int flick = 0;

    flick ++;

    if ( flick < 5000 )
    {
        tcMapSetLandMap( gameData.map );
    }
    else
    {
        tcMapSetWaterMap( gameData.map );
    }

    if ( flick > 10000 )
    {
        flick = 0;
    }
    
}

void handleAnimations( tcGameData_t gameData )
{

}

void placeTileOnCanvas( tcCanvas_t *canvas, tcTile_t *tile, int x_pos, int y_pos )
{
    int x, x_rel;
    int y, y_rel;
    tcTileSquare_t *square;
    tcCanvasItem_t *item; 

    for ( x = 0; x <= 1; x++ )
    {
        for ( y = 0; y <= 1; y++ )
        {
            square = tile->squares[y * 2 + x ];
            x_rel = x_pos + x;
            y_rel = y_pos + y;
            if ( x_rel >= 0 && x_rel < canvas->width && y_rel >= 0 && y_rel < canvas->height )
            {
                item = canvas->content + ( x_rel + y_rel * canvas->width );
                item->backGroundColor = square->backgroundColor;
                item->color = square->color;
                item->content = square->character;        
            }
        }
    }
}

void drawCanvas( tcGameData_t gameData )
{
    tcCanvas_t *canvas = gameData.canvas;
    tcTile_t *tile;
    uint8_t tile_nr;

    for ( int x = 0; x < canvas->width; x+=2 )
    {
        for ( int y = 0; y < canvas->height; y+=2 )
        {
            tile_nr = gameData.map->tiles[ y * gameData.map->width + x].base_content - 1;
            tile = gameData.store->usableTiles[tile_nr]->tiles[0];
            placeTileOnCanvas( canvas, tile, x, y );       
        }
    }
}

void renderCanvas( tcGameData_t gameData )
{
    tcRendererRenderCanvas( gameData.canvas );
}

void waitTime()
{
    
}
