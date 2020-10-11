#include <stdio.h>
#include <stdlib.h>

#include "renderer.h"
#include "canvas.h"

char *progname;


void setTestVal( tcCanvasItem_t *item )
{
    item->color = 4;
    item->backGroundColor = 12;
    item->content = '9';
    item->updated = 1;
}


int main( int argc, char** argv )
{
    progname = argv[0];
        
    tcRendererInit();
    tcCanvas_t *canvas = tcRendererCreateCanvas();
    tcRendererRenderCanvas( canvas );
    
    return EXIT_SUCCESS;
}


