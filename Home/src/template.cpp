#include <stdio.h> //printf, scanf
#include <stdlib.h> //getch()
#include <conio.h>
#include <graphics.h>
int main()
{
    int gm, gd = DETECT;
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; //static file
    //Declaration variable with datatype
    initgraph(&gd, &gm, data);
    cleardevice();

    //Enter script here;

    getch();
    closegraph();

    return 0;
}