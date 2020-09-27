#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>
#include <assert.h>
#include <inttypes.h>

#include "renderer.h"

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
