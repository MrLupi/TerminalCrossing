#ifndef TC_MEM_INCLUDED
#define TC_MEM_INCLUDED

/*
struct __known_ptr
{
    void *ptr;
    size_t length;
    char desc[20];
};

typedef struct __known_ptr tcKnownPtr_t;

static int numberOfKnownPointers = 0;
static int allocatedKnowPointers = 0;
static tcKnownPtr_t *listOfKnownPointers;
*/

void *balloc( size_t length );

int smallestInt( int i1, int i2 );




#endif // TC_MEM_INCLUDED
