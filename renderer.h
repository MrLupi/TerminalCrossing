#ifndef TC_RENDERER_INLCUDED 
#define TC_RENDERER_INLCUDED 
#include <termios.h>
#include <inttypes.h>

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

#define CBLU 1
#define CGRN 2
#define CCYN 3
#define CRED 4
#define CMAG 5
#define CYEL 6
#define CWHT 7
#define CBLK 8
#define BCBLU 11
#define BCGRN 12
#define BCCYN 13
#define BCRED 14
#define BCMAG 15
#define BCYEL 16
#define BCWHT 17
#define BCNRM 10
#define CNRM 0


struct __tc_renderer
{
    
};

typedef struct __tc_renderer tcRenderer_t;


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


tcCanvas_t *createTcCanvas( int width, int height );
void destroyTcCanvas( tcCanvas_t **canvas );
void tcRendererDrawCanvas( tcCanvas_t *canvas );


int  tcRendererGetKey();
void tcRendererClearScreen();
void tcRendererTextColor(int c);
void tcRendererGotoyx(int y, int x);
void tcRendererGotoyxc(int y, int x,int c);
int tcRendererInit( tcRenderer_t *renderer );
int tcRendererDraw( tcRenderer_t *renderer );




#endif // TC_RENDERER_INLCUDED 