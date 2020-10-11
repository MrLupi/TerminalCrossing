#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mem.h"

void *balloc( size_t length )
{
    void *ptr;
    
    ptr = malloc( length );
    memset( ptr, 0, length );
    
    return ptr;
}

int smallestInt( int i1, int i2 )
{
    return i1 > i2 ? i2 : i1;
}