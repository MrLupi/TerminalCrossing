#include <stdlib.h>
#include <sys/ioctl.h>

#include "canvas.h"
#include "mem.h"
#include "renderer.h"

static void tcCanvasResetContent( tcCanvas_t *canvas )
{
    int count = canvas->height * canvas->width;

    for ( int i = 0; i < count; i++ )
    {
        canvas->content[i].updated = 1;
        canvas->content[i].color = CWHT;
        canvas->content[i].backGroundColor = CBLK;
        canvas->content[i].content = ' ';
    }
}

static void tcCopyCanvasContent( tcCanvas_t *source, tcCanvas_t *target )
{
    int width = smallestInt( source->width, target->width );
    int height = smallestInt( source->height, target->height );
    int targetIndex = 0;
    int sourceIndex = 0;

    for ( int y = 0; y < height; y++ )
    {
        for ( int x = 0; x < width; x++ )
        {
            target->content[targetIndex++] = source->content[sourceIndex++];            
        }
        targetIndex += ( target->width - width );
        sourceIndex += ( source->width - width );
    }
}


tcCanvas_t *tcCreateTcCanvas( int width, int height )
{
    tcCanvas_t *canvas;
    
    size_t canvasSize = sizeof( tcCanvas_t );    
    int numberOfCanvasItems = width * height;
    size_t sizeOfCanvasItems = numberOfCanvasItems * sizeof( tcCanvasItem_t );
    
    canvas = ( tcCanvas_t * ) balloc( canvasSize );
    canvas->content = ( tcCanvasItem_t* ) balloc( sizeOfCanvasItems );
   
    canvas->width = width;
    canvas->height = height;

    tcCanvasResetContent( canvas );
    
    return canvas;
}

void tcDestroyTcCanvas( tcCanvas_t **canvas )
{
    free( ( *canvas )->content );
    free( ( *canvas ) );
    *canvas = NULL;
}

void tcSetCanvasSize( tcCanvas_t *canvas, struct winsize terminalSize )
{
    tcCanvas_t *newCanvas = tcCreateTcCanvas( terminalSize.ws_col, terminalSize.ws_row );
    
    tcCopyCanvasContent( canvas, newCanvas );

    free( canvas->content );
    canvas->content = newCanvas->content;
    free( newCanvas );       
}