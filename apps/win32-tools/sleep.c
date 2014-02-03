#include "windows.h"

int main(int argc, char* argv[])
{
    int sec = 1;
    
    if ( argc > 1 )
        sec = atoi(argv[1]);
      
    Sleep( sec * 1000 );    
    
    return 0; 
}

