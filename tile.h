#ifndef TC_TILE_H_INCLUDE
#define TC_TILE_H_INCLUDE
#include <inttypes.h>


typedef struct __tc_tile_square
{
    uint8_t character;
    uint8_t color;
    uint8_t backgroundColor;
    uint8_t reserved;
} tcTileSquare_t;

tcTileSquare_t *tcCreateTileSquare();
void tcDestroyTileSquare( tcTileSquare_t **square );
void tcSetTileSquare( tcTileSquare_t *square, uint8_t character, uint8_t color, uint8_t backgroundColor );
void tcSetTileSquareStr( tcTileSquare_t *square, const char *string );

typedef struct __tc_tile
{
    tcTileSquare_t *squares[4];
} tcTile_t;

tcTile_t *tcCreateTile();
void tcAddTileSquareToTile( tcTile_t *tile, tcTileSquare_t *square );
void tcAddTileSquaresToTile( tcTile_t *tile, tcTileSquare_t **squares );
void tcDestroyTile( tcTile_t **tile );


typedef struct __tc_usable_tile
{
    tcTile_t **tiles;
    int16_t numberOfTiles;
    int16_t options;
} tcUsableTile_t;

tcUsableTile_t *tcCreateUsableTile();
void tcDestroyUsableTile( tcUsableTile_t **tile );


typedef struct __tc_tile_store
{
    tcTileSquare_t **tileSquares;
    tcTile_t **tiles;
    tcUsableTile_t **uTiles;
} tcTileStore_t;

tcTileStore_t *tcCreateTileStore();
void tcDestroyTileStore( tcTileStore_t **store );

#endif // TC_TILE_H_INCLUDE