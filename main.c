#include <stdio.h>
#include <stdlib.h>

#include "renderer.h"


char *progname;


int main( int argc, char** argv )
{
    progname = argv[0];
    
    int i = 0;
    
    for ( i = 0; i <=8; i++ )
    {
        tcRendererGotoyxc( i, 1, i);
        printf("Hello, World");
    }
    
    return EXIT_SUCCESS;
}
