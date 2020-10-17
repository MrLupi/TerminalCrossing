#ifndef TC_TILE_H_INCLUDE
#define TC_TILE_H_INCLUDE
#include <inttypes.h>

const char* water1 = { '~' ,CWHT, CBLU };
const char* water2 = { ' ' ,CWHT, CBLU };
const char* land1 = { '.', CWHT, CYEL };

typedef struct __tc_tile_square
{
    uint8_t character;
    uint8_t color;
    uint8_t backgroundColor;
    uint8_t options;
} tcTileSquare_t;

tcTileSquare_t *tcCreateTileSquare();
void tcDestroyTileSquare( tcTileSquare_t **square );
void tcSetTileSquare( tcTileSquare_t *square, uint8_t character, uint8_t color, uint8_t backgroundColor );
tcTileSquare_t *tcSetTileSquareStr( const char *string );
void tcSetOptionsTileSquare( tcTileSquare_t *square, uint8_t options );


typedef struct __tc_tile
{
    tcTileSquare_t *squares[4];
} tcTile_t;

tcTile_t *tcCreateTile();
void tcAddTileSquareToTile( tcTile_t *tile, tcTileSquare_t *square );
void tcDestroyTile( tcTile_t **tile );

#define TC_USABLE_TILE_OPTION_ANIMATED 1

typedef struct __tc_usable_tile
{
    tcTile_t **tiles;
    int16_t numberOfTiles;
    int16_t allocated;    
    int16_t options;
} tcUsableTile_t;

tcUsableTile_t *tcCreateUsableTile();
void tcIncreaseUsableTileSize( tcUsableTile_t *tile );
void tcAddTileToUsableTile( tcUsableTile_t *usableTile, tcTile_t *tile );
void tcSetOptionUsableTile( tcUsableTile_t *tile, uint8_t options );
void tcResetOptionUsableTile( tcUsableTile_t *tile, uint8_t options );
void tcDestroyUsableTile( tcUsableTile_t **tile );


typedef struct __tc_tile_store
{
    tcTileSquare_t **tileSquares;
    uint16_t allocatedTileSquares;
    uint16_t numberOfTileSquares;
    tcTile_t **tiles;
    uint16_t allocatedTiles;
    uint16_t numberOfTiles;
    tcUsableTile_t **usableTiles;
    uint16_t allocatedUsableTiles;
    uint16_t numberOfUsableTiles;
} tcTileStore_t;

tcTileStore_t *tcCreateTileStore();
void tcTileStoreIncreaseTileSquareSize( tcTileStore_t *store );
void tcTileStoreIncreaseTileSize( tcTileStore_t *store );
void tcTileStoreIncreaseUsableTileSize( tcTileStore_t *store );
void tcTileStoreAddTileSquare( tcTileStore_t *store, tcTileSquare_t *square );
void tcTileStoreAddTileSquare( tcTileStore_t *store, tcTileSquare_t *square );
void tcTileStoreAddTile( tcTileStore_t *store, tcTile_t *tile );
void tcDestroyTileStore( tcTileStore_t **store );

tcTileStore_t *initializeTileStore();
#endif // TC_TILE_H_INCLUDE