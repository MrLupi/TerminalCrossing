#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#include "tcmap.h"
#include "mem.h"

/*
struct __tc_drawable_tile_content
{
    char character;
    uint8_t color;
    uint8_t backgroundColor;
};
typedef struct __tc_drawable_tile_content tcDrawableTileContent_t;

struct __tc_drawable_tile
{   
    tcDrawableTileContent_t *contents;
    uint16_t count;
};
typedef struct __tc_drawable_tile tcDrawableTile_t;
*/

tcDrawableTile_t *tcMapcreateDrawableTile( uint8_t *data, uint32_t count )
{
    tcDrawableTile_t *newDrawableTile;
    newDrawableTile = (tcDrawableTile_t*) balloc( sizeof( tcDrawableTile_t ) );

    uint32_t tileCount = count / TC_MAP_DRAWABLE_TILE_CHARACTER_COUNT;
    newDrawableTile->contents = (tcDrawableTileContent_t*) balloc( sizeof( tcDrawableTileContent_t ) * count );

    for (int i = 0; i < tileCount; i++ )
    {
        tcDrawableTileContent_t *content = newDrawableTile->contents+i;
        content->backgroundColor = data[i + 0];
        content->color = data[i + 1];
        content->character = (char) data[i + 2];
    }

    return newDrawableTile;
}

void tcMapDistroyDrawableTile( tcDrawableTile_t **drawableTile )
{
    free( ( *drawableTile )->contents );
    free( ( *drawableTile ) );
    *drawableTile = NULL;
}

tcDrawableTile_t **tcMapLoadDrawableTilesList()
{
    tcDrawableTile_t **drawableTilesList;
    int numberOfTiles;
    
    numberOfTiles = 1;
    drawableTilesList = (tcDrawableTile_t **) balloc( sizeof( tcDrawableTile_t * ) *numberOfTiles );
    //drawableTilesList[0] = tcMapcreateDrawableTile( {BCBLU, CWHT, '~' }, 1 )

    return drawableTilesList;
}

void tcMapDestroyDrawableTilesList( tcDrawableTile_t ***drawableTilesList )
{

}



tcMapTile_t *tcMapCreateMapTile()
{
    tcMapTile_t *newTile;
    newTile = (tcMapTile_t*) balloc( sizeof( tcMapTile_t ) );
    return newTile;
}

void tcMapDestroyMapTile( tcMapTile_t **tile )
{
    free( ( *tile ) );
    *tile = NULL;
}

static void tcMapSetWaterMap( tcMap_t *map )
{
    int i;
    tcMapTile_t *tiles;

    tiles = map->tiles;

    for ( i = 0; i < map->count; i++ )
    {
        tiles[i].base_content = TC_MAP_BASE_CONTENT_SEA;
    }
}

tcMap_t *tcMapCreateMap()
{
    tcMap_t *newMap;

    newMap = (tcMap_t*) balloc( sizeof(tcMap_t) );
    newMap->width = TC_MAP_DEFAULT_WIDTH;
    newMap->height = TC_MAP_DEFAULT_HEIGHT;
    newMap->count = newMap->width * newMap->height;
    
    newMap->tiles = (tcMapTile_t*) balloc( sizeof( tcMapTile_t ) * newMap->count );

    tcMapSetWaterMap( newMap );
    return newMap;
}

void tcMapToCanvas( tcMap_t *map, tcCanvas_t *canvas )
{

}

void tcMapDestroyMap( tcMap_t **map )
{
    free( ( *map )->tiles );
    free( ( *map ) );
    *map = NULL;
}