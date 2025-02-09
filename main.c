#include <REGX52.H>
#include "MatrixLED.h"
#include "Timer0.h"
#include <stdio.h>
#include <stdlib.h>
#include <LCD1602.h>

int a[8][8] = {0};

// 定义链表
typedef struct Snake
{
    int x, y;
    struct Snake *next;
} Snake;

Snake *head = NULL;
Snake *body1 = NULL;
Snake *body2 = NULL;
Snake *current = NULL;

void main()
{
    int i, j;
    // 初始化LED,时钟，蛇的初始位置
    MatrixLED_Init();
    Timer0Init();
    LCD_Init();
    // 初始化链表
    head = (Snake *)malloc(sizeof(Snake));
    head->x = 0;
    head->y = 0;

    body1 = (Snake *)malloc(sizeof(Snake));
    body1->x = 1;
    body1->y = 0;
    head->next = body1;

    body2 = (Snake *)malloc(sizeof(Snake));
    body2->x = 1;
    body2->y = 1;
    body1->next = body2;
    body2->next = NULL;

    // 写入数组
    current = head;
    while (current != NULL)
    {
        a[current->x][current->y] = 1;
        current = current->next;
    }

    // 调试输出数组内容
    
            LCD_ShowNum(1,1 , a[1][1], 1);

    // 输出
    while (1)
    {
        MatrixLED(a);
    }
}

void Timer0_Routine() interrupt 1
{
    static unsigned int T0Count;
    TL0 = 0x66; // 设置定时初值
    TH0 = 0xFC; // 设置定时初值
    T0Count++;

    if (T0Count >= 1000)
    {
        T0Count = 0;
    }
}