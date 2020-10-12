#ifndef TCMAP_H_INCLUDED
#define TCMAP_H_INCLUDED

#include <inttypes.h>
#include "renderer.h"
#include "canvas.h"

#define TC_MAP_DEFAULT_WIDTH 800
#define TC_MAP_DEFAULT_HEIGHT 800

enum base_map
{
    TC_MAP_BASE_CONTENT_SEA = 1,
    TC_MAP_BASE_CONTENT_RIVER,
    TC_MAP_BASE_CONTENT_BEACH,
    TC_MAP_BASE_CONTENT_LAND
};

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
void tcMapDestroyMap( tcMap_t **map );









#endif // TCMAP_H_INCLUDED
