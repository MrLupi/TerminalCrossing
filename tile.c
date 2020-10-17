#include <stdlib.h>

#include "tcPublicColors.h"
#include "mem.h"
#include "tile.h"

/*
 * typedef struct __tc_tile_square
   {
        uint8_t character;
        uint8_t color;
        uint8_t backgroundColor;
        uint8_t reserved;
    } tcTileSquare_t;
*/

tcTileSquare_t *tcCreateTileSquare()
{
    tcTileSquare_t *entity;
    entity = ( tcTileSquare_t* ) balloc ( sizeof( tcTileSquare_t ) );
    return entity;
}

void tcDestroyTileSquare( tcTileSquare_t **square )
{
    free( *square );
    *square = NULL;
}

void tcSetTileSquare( tcTileSquare_t *square, uint8_t character, uint8_t color, uint8_t backgroundColor )
{
    square->character = character;
    square->color = color;
    square->backgroundColor = backgroundColor;
}

tcTileSquare_t *tcSetTileSquareStr( const char *string )
{
    tcTileSquare_t *square;
    square = tcCreateTileSquare();

    square->character = string[0];
    square->color = string[1];
    square->backgroundColor = string[2];
}

void tcSetOptionsTileSquare( tcTileSquare_t *square, uint8_t options )
{
    square->options = options;
}


tcTile_t *tcCreateTile()
{
    tcTile_t *entity;
    entity = ( tcTile_t* ) balloc ( sizeof( tcTile_t ) );
    return entity;
}

void tcAddTileSquareToTile( tcTile_t *tile, tcTileSquare_t *square )
{
    for( int pos = 0; pos < 4; pos++ )
    {
        if ( tile->squares[pos] == NULL )
        {
            tile->squares[pos] = square;
        }
    }
}



void tcDestroyTile( tcTile_t **tile )
{
    for( int pos = 0; pos < 4; pos++ )
    {
        free( ( *tile )->squares[pos] );
    }
    free( *tile );
    *tile = NULL;
}


tcUsableTile_t *tcCreateUsableTile()
{
    tcUsableTile_t *entity;
    entity = ( tcUsableTile_t* ) balloc ( sizeof( tcUsableTile_t ) );

    entity->allocated = 5;
    entity->tiles = ( tcTile_t ** ) balloc( sizeof ( tcTile_t *) * entity->allocated );

    return entity;
}

void tcIncreaseUsableTileSize( tcUsableTile_t *tile )
{
    tile->allocated += 5;
    tile->tiles = ( tcTile_t ** ) realloc( tile->tiles, sizeof ( tcTile_t *) * tile->allocated );
}

void tcAddTileToUsableTile( tcUsableTile_t *usableTile, tcTile_t *tile )
{
    if ( usableTile->allocated <= usableTile->numberOfTiles )
    {
        tcIncreaseUsableTileSize( usableTile );
    }
    usableTile->tiles[usableTile->numberOfTiles++] = tile;

    if ( usableTile->numberOfTiles > 1 )
    {
        tcSetOptionUsableTile( usableTile, TC_USABLE_TILE_OPTION_ANIMATED );
    }
}

void tcSetOptionUsableTile( tcUsableTile_t *tile, uint8_t options )
{
    tile->options |= options;
}

void tcSetOptionUsableTile( tcUsableTile_t *tile, uint8_t options )
{
    tile->options &= ~options;
}

void tcDestroyUsableTile( tcUsableTile_t **tile )
{
    free( *tile );
    *tile = NULL;
}


tcTileStore_t *tcCreateTileStore()
{
    tcTileStore_t *entity;
    entity = ( tcTileStore_t* ) balloc ( sizeof( tcTileStore_t ) );
    
    entity->allocatedTileSquares = 5;
    entity->tileSquares = ( tcTileSquare_t ** ) balloc ( sizeof( tcTileSquare_t * ) * entity->allocatedTileSquares );

    entity->allocatedTiles = 5;
    entity->tiles = ( tcTile_t ** ) balloc ( sizeof( tcTile_t * ) * entity->allocatedTiles );

    entity->allocatedUsableTiles = 5;
    entity->usableTiles = ( tcUsableTile_t ** ) balloc ( sizeof( tcUsableTile_t * ) * entity->allocatedUsableTiles );

    return entity;
}

void tcTileStoreIncreaseTileSquareSize( tcTileStore_t *store )
{
    store->allocatedTileSquares += 5;
    store->tileSquares = ( tcTileSquare_t ** ) realloc( store->tileSquares, sizeof ( tcTileSquare_t *) * store->allocatedTileSquares );
}

void tcTileStoreIncreaseTileSize( tcTileStore_t *store )
{
    store->allocatedTiles += 5;
    store->tiles = ( tcTile_t ** ) realloc( store->tiles, sizeof ( tcTile_t *) * store->allocatedTiles );
}

void tcTileStoreIncreaseUsableTileSize( tcTileStore_t *store )
{
    store->allocatedTileSquares += 5;
    store->usableTiles = ( tcUsableTile_t ** ) realloc( store->usableTiles, sizeof ( tcUsableTile_t *) * store->allocatedTileSquares );
}

void tcTileStoreAddTileSquare( tcTileStore_t *store, tcTileSquare_t *square )
{
    if ( store->allocatedTileSquares <= store->numberOfTileSquares )
    {
        tcTileStoreIncreaseTileSquareSize( store );
    }
    store->tileSquares[store->numberOfTileSquares++] = square;
}

void tcTileStoreAddTile( tcTileStore_t *store, tcTile_t *tile )
{
    if ( store->allocatedTiles <= store->numberOfTiles )
    {
        tcTileStoreIncreaseTileSize( store );
    }
    store->tiles[store->numberOfTiles++] = tile;
}

void tcTileStoreAddUsableTile( tcTileStore_t *store, tcUsableTile_t *usableTile )
{
    if ( store->allocatedUsableTiles <= store->numberOfUsableTiles )
    {
        tcTileStoreIncreaseUsableTileSize( store );
    }
    store->usableTiles[store->numberOfUsableTiles++] = usableTile;
}

void tcDestroyTileStore( tcTileStore_t **store )
{
    free( *store );
    *store = NULL;
}

tcTileStore_t *initializeTileStore()
{    
    tcTileStore_t *store = tcCreateTileStore();

    tcTileSquare_t *water1square = tcSetTileSquareStr( water1 );
    tcTileSquare_t *water2square = tcSetTileSquareStr( water2 );
    tcTileSquare_t *land1square = tcSetTileSquareStr( land1 );

    tcTileStoreAddTileSquare( store, water1square );
    tcTileStoreAddTileSquare( store, water2square );
    tcTileStoreAddTileSquare( store, land1square );
    
    tcTile_t *waterTile = tcCreateTile();
    tcAddTileSquareToTile( waterTile, water1square );
    tcAddTileSquareToTile( waterTile, water2square );
    tcAddTileSquareToTile( waterTile, water2square );
    tcAddTileSquareToTile( waterTile, water1square );

    tcTileStoreAddTile( store, waterTile );

    tcUsableTile_t *usableWaterTile = tcCreateUsableTile();
    tcAddTileToUsableTile( usableWaterTile, waterTile );

    tcTileStoreAddUsableTile( store, usableWaterTile );

    tcTile_t *landTile = tcCreateTile();
    tcAddTileSquareToTile( landTile, land1square );
    tcAddTileSquareToTile( landTile, land1square );
    tcAddTileSquareToTile( landTile, land1square );
    tcAddTileSquareToTile( landTile, land1square );

    tcTileStoreAddTile( store, landTile );

    tcUsableTile_t *usableLandTile = tcCreateUsableTile();
    tcAddTileToUsableTile( usableLandTile, landTile );

    tcTileStoreAddUsableTile( store, landTile );
}
