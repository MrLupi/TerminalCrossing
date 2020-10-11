#ifndef TERMINAL_CROSSING_CANVAS_H_INCLUDED
#define TERMINAL_CROSSING_CANVAS_H_INCLUDED
#include <inttypes.h>
#include <stdlib.h>
#include <sys/ioctl.h>


struct __tc_canvas_item
{
    uint8_t color;
    uint8_t backGroundColor;
    uint8_t updated;
    char content;   
};
typedef struct __tc_canvas_item tcCanvasItem_t;


struct __tc_canvas
{
    int width;
    int height;
    tcCanvasItem_t *content;
};
typedef struct __tc_canvas tcCanvas_t;

tcCanvas_t *tcCreateTcCanvas( int width, int height );
void tcDestroyTcCanvas( tcCanvas_t **canvas );
void tcSetCanvasSize( tcCanvas_t *canvas, struct winsize terminalSize );

#endif // TERMINAL_CROSSING_CANVAS_H_INCLUDED
