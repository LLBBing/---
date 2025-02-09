#include <stdio.h>

unsigned char Hex(int a[8][8], int column)
{
    unsigned char hexValue = 0;
    int i;
    for (i = 0; i < 8; i++)
    {
        hexValue <<= 1;
        if (a[i][column] == 1)
        {
            hexValue |= 1;
        }
    }
    return hexValue;
}
