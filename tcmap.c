#include <stdlib.h>
#include <string.h>

#include "tcmap.h"
#include "mem.h"

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

void tcMapDestroyMap( tcMap_t **map )
{
    free( ( *map )->tiles );
    free( ( *map ) );
    *map = NULL;
}