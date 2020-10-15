#ifndef RENDERER_H_INLCUDED 
#define RENDERER_H_INLCUDED 
#include <termios.h>
#include <inttypes.h>
#include <stdio.h>
#include "canvas.h"
#include "tcPublicColors.h"

//static int _tcRendererWidth;
//static int _tcRendererHeight;

#define BGNRM  "\x1B[49m"
#define BGRED  "\x1B[41m"
#define BGGRN  "\x1B[42m"
#define BGYEL  "\x1B[43m"
#define BGBLU  "\x1B[44m"
#define BGMAG  "\x1B[45m"
#define BGCYN  "\x1B[46m"
#define BGWHT  "\x1B[47m"
#define BGCLEAR "\x1B[3;J\x1B[H\x1B[2J"


#define GNRM  "\x1B[0m"
#define GBLK  "\x1B[30m"
#define GRED  "\x1B[31m"
#define GGRN  "\x1B[32m"
#define GYEL  "\x1B[33m"
#define GBLU  "\x1B[34m"
#define GMAG  "\x1B[35m"
#define GCYN  "\x1B[36m"
#define GWHT  "\x1B[37m"
#define CLEAR "\x1B[3;J\x1B[H\x1B[2J"


#define TC_RENDERER_MAXIMUMFRAMERATE 10



void tcRendererInit();
tcCanvas_t *tcRendererCreateCanvas();
void tcRendererRenderCanvas( tcCanvas_t *canvas );

int  tcRendererGetKey();
void tcRendererClearScreen();
void tcRendererTextColor(int c);
void tcRendererGotoyx(int y, int x);
void tcRendererGotoyxc(int y, int x,int c);





#endif // RENDERER_H_INLCUDED 
