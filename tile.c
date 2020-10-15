#include <stdlib.h>
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

void tcSetTileSquareStr( tcTileSquare_t *square, const char *string )
{
    square->character = string[0];
    square->color = string[1];
    square->backgroundColor = string[2];
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

void tcAddTileSquaresToTile( tcTile_t *tile, tcTileSquare_t **squares )
{
    for( int pos = 0; pos < 4; pos++ )
    {
        tile->squares[pos] = squares[pos];
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
    return entity;
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
    return entity;
}

void tcDestroyTileStore( tcTileStore_t **store )
{
    free( *store );
    *store = NULL;
}
