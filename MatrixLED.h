#ifndef __MATRIXLED_H__
#define __MATRIXLED_H__

void MatrixLED_Init();
void MatrixLED_ShowColumn(unsigned char Column, unsigned char Data);
void MatrixLED(int a[8][8]);

#endif