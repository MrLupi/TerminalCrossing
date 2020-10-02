#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>
#include <assert.h>
#include <inttypes.h>

#include "renderer.h"
#include "mem.h"



tcCanvas_t *createTcCanvas( int width, int height )
{
    tcCanvas_t *canvas;
    
    size_t canvasSize = sizeof( tcCanvas_t );    
    size_t numberOfCanvasItems = width * height * sizeof( tcCanvasItem_t );
    
    canvas = ( tcCanvas_t * ) balloc( canvasSize );
    canvas->content = ( tcCanvasItem_t* ) balloc( numberOfCanvasItems );
    
    canvas->width = width;
    canvas->height = height;
    
    return canvas;
}

void destroyTcCanvas( tcCanvas_t **canvas )
{
    free( ( *canvas )->content );
    free( ( *canvas ) );
    *canvas = NULL;
}

static int tcRendererIsEqualCanvasItem( tcCanvasItem_t* item1, tcCanvasItem_t* item2 )
{
    return item1->backGroundColor == item2->backGroundColor && item1->color == item2->color && item1->content == item2->content;
}

static void tcRendererAssignCanvasItem( tcCanvasItem_t* source, tcCanvasItem_t* target )
{
   target->backGroundColor = source->backGroundColor;
   target->color = source->color;
   target->content = source->content;
   target->updated = 1;
}



void tcRendererDrawCanvas( tcCanvas_t *canvas )
{
    int x;
    int y;
    int i = 0;
    
    for ( y = 1; y < canvas->height; y++ )
    {
        for ( x = 1; x < canvas->width; x++ )
        {            
            if ( canvas->content[i].updated )
            {
                tcRendererTextColor( canvas->content[i].color );
                tcRendererTextColor( canvas->content[i].backGroundColor );
                tcRendererGotoyx( y, x );
                putchar( canvas->content[i].content );
                canvas->content[i].updated = 0;
            }
            i++;
        }
    }
}

void tcRendererSetUpdateCanvas( tcCanvas_t *canvas, tcCanvas_t *newCanvas)
{
    int x;
    int y;
    int i = 0;
    
    for ( y = 1; y < canvas->height; y++ )
    {
        for ( x = 1; x < canvas->width; x++ )
        {            
            if ( !tcRendererIsEqualCanvasItem( canvas->content + i, newCanvas->content + i ) )
            {                
                tcRendererAssignCanvasItem( newCanvas->content + i, canvas->content + i );
            }
                
            i++;
        }
    }
}

int tcRendererGetKey() 
{
  int pressedKey = 0;
  size_t length;

  struct termios oldTerminalOptions;
  struct termios temporaryTerminalOptions;
  
  length = sizeof( temporaryTerminalOptions );
  
  tcgetattr( STDIN_FILENO, &oldTerminalOptions );

  memcpy( &temporaryTerminalOptions, &oldTerminalOptions, length );
  temporaryTerminalOptions.c_lflag &= ~( ECHO | ECHOPRT | ECHOKE | ECHOE | ECHOK | ECHONL | ICRNL | ICANON );
  
  tcsetattr( STDIN_FILENO, TCSANOW, &temporaryTerminalOptions );
  
  pressedKey=getchar();
  
  tcsetattr( STDIN_FILENO, TCSANOW, &oldTerminalOptions );
  
  return( pressedKey );
}

void tcRendererClearScreen()
{
  printf( CLEAR );
}

void tcRendererTextColor( int colour )
{
  switch ( colour ) 
  {
    case 1: printf( GBLU ); break;
    case 2: printf( GGRN ); break;
    case 3: printf( GCYN ); break;
    case 4: printf( GRED ); break;
    case 5: printf( GMAG ); break;
    case 6: printf( GYEL ); break;
    case 7: printf( GWHT ); break;
    case 8: printf( GBLK ); break;
    case 11: printf( BGBLU ); break;
    case 12: printf( BGGRN ); break;
    case 13: printf( BGCYN ); break;
    case 14: printf( BGRED ); break;
    case 15: printf( BGMAG ); break;
    case 16: printf( BGYEL ); break;
    case 17: printf( BGWHT ); break;

    default: 
             printf( GNRM );
             printf( BGNRM );
             break;
  }
}

void tcRendererGotoyx( int y, int x ) 
{
  printf( "%c[%d;%df",0x1B,y,x );
}

void tcRendererGotoyxc( int y, int x, int colour )
{
  tcRendererTextColor( colour );
  tcRendererGotoyx( y, x );
}
