#ifndef TCMAP_H_INCLUDED
#define TCMAP_H_INCLUDED

#include <inttypes.h>
#include "renderer.h"
#include "canvas.h"

#define TC_MAP_DRAWABLE_TILE_CHARACTER_COUNT 3

#define TC_MAP_DEFAULT_WIDTH 800
#define TC_MAP_DEFAULT_HEIGHT 800

enum base_map
{
    TC_MAP_BASE_CONTENT_SEA = 1,
    TC_MAP_BASE_CONTENT_RIVER,
    TC_MAP_BASE_CONTENT_BEACH,
    TC_MAP_BASE_CONTENT_LAND
};

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

tcDrawableTile_t **tcMapLoadDrawableTilesList();
void tcMapDestroyDrawableTilesList( tcDrawableTile_t ***drawableTilesList );

tcDrawableTile_t *tcMapcreateDrawableTile( uint8_t *data, uint32_t count );
void tcMapDistroyDrawableTile( tcDrawableTile_t **drawableTile );

struct __tc_map_tile
{
    uint8_t base_content;
};
typedef struct __tc_map_tile tcMapTile_t;

tcMapTile_t *tcMapCreateMapTile();
void tcMapDestroyMapTile( tcMapTile_t **tile );

struct __tc_map
{
    uint16_t width;
    uint16_t height;
    uint32_t count;
    tcMapTile_t *tiles;
};
typedef struct __tc_map tcMap_t;

tcMap_t *tcMapCreateMap();
void tcMapToCanvas( tcMap_t *map, tcCanvas_t *canvas );
void tcMapDestroyMap( tcMap_t **map );









#endif // TCMAP_H_INCLUDED
