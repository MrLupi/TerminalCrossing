#include <stdio.h>
#include <stdlib.h>

#include "renderer.h"


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
        
    tcCanvas_t *canvas;
    
    canvas = createTcCanvas( 20, 20 );
    
    for ( int i = 12; i < 64; i++ )
    {
        setTestVal( canvas->content + i );
    }
      
    tcRendererDrawCanvas( canvas );
    
    return EXIT_SUCCESS;
}


