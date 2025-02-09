#include <REGX52.H>
#include "MatrixLED.h"
#include "Delay.h"
#include "hex.h"

int a[8][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
};


void main()
{
    MatrixLED_Init();


    while (1)
    { 
        int i;
        for (i=0;i<8;i++)
        {
            MatrixLED_ShowColumn(i, Hex(a, i));
        }
           
    }
}