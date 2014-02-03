#include "windows.h"
#include "string.h"


void send_virtual_key(WORD vk,int key_up)
{
    INPUT input;
    memset( &input,0, sizeof(input) );
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = vk;
    if ( key_up )
        input.ki.dwFlags = KEYEVENTF_KEYUP;
        
    SendInput( 1, &input, sizeof(input) );
}

void send_virtual_key_press(WORD vk)
{
    send_virtual_key( vk, 0 );
    Sleep(100);
    send_virtual_key( vk, 1 );    
}

void send_char(char c)
{
    WORD vk = VkKeyScan(c);
    send_virtual_key_press( vk );
}

int main(int argc, char* argv[])
{
    char str[512];
    memset(str, 0, 512 );
        
    if ( argc > 1 )
        strncpy( str, argv[1], 511 );
    else
        return -1;
      
    int index = 0;
    int len = strlen(str);
    char* s = &str[0];
    while( *s )
    {
        char c = *s;
        if ( c == '\\' )
        {
            s++;
            c = *s;
            if ( c == 'r')
            {
                send_virtual_key_press(VK_RETURN);
            }
                
        }  
        else
            send_char( c ); 
        s++;
    }
    
    return 0;     
}
