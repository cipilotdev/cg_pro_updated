#include <stdio.h> //input dan output 
#include <stdlib.h> 
#include <conio.h> //getch()
#include <graphics.h>

int x_mid, y_mid;

void bre_line(int xa, int ya, int xb, int yb)
{
    int delta_x, delta_y, p;
    int xtemp, ytemp;
    int x, y, i;
    delta_x = xb - xa;
    delta_y = yb - ya;

    /* if (delta_x >= 0) xtemp = 1;
    else xtemp = -1;

    if (delta_y >= 0) ytemp = 1; 
    else ytemp = -1; */
    setcolor(RED);
   
    x = xa, y = ya;
    putpixel(x + x_mid, y_mid - y, WHITE);
    i = 0;
    if (abs(delta_y) < abs(delta_x))
    {
        p = (2 * delta_y) - (delta_x);
        do
        {
            if (p < 0)
            {
                x = x + 1;
                p = p + 2 * delta_y * ytemp;
                putpixel(x + x_mid, y_mid - y, WHITE);
            }
            else
            {
                x = x + 1;
                y = y + 1;
                p = p + 2 * delta_y - 2 * delta_x;
                putpixel(x + x_mid, y_mid - y, WHITE);
            }
            i++;
        }while(i<=delta_x);
    }
    else
    {
        p = (2 * delta_x ) - (delta_y);
        do
        {
            if (p < 0)
            {
                y = y + 1;
                p = p + 2 * delta_x;
                putpixel(x + x_mid, y_mid - y, WHITE);
            }
            else
            {
                x = x + 1;
                y = y + 1;
                p = p + 2 * delta_x - 2 * delta_y;
                putpixel(x + x_mid, y_mid - y, WHITE);
            }
            i++;
        }while(i<=delta_y);
    }
}

void square_four(int xa, int ya, int xb, int yb)
{
    bre_line(xa, ya, xb, ya);
    bre_line(xa, ya, xa, yb);
    bre_line(xb, ya, xb, yb);
    bre_line(xa, yb, xb, yb);
}

int main()
{
    int xmax, ymax, gm, gd = DETECT;
    int n;
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; //static file
    
    initgraph(&gd, &gm, data);
    cleardevice();
    
    xmax = getmaxx(); // to get the co-ordinates i.e. x & y
    ymax = getmaxy();
    x_mid = xmax/2;
    y_mid = ymax/2;
    //coding graphics
    
    setcolor(RED);
    line(0, y_mid, xmax, y_mid);
    line(x_mid, 0, x_mid, ymax);
    square_four(10,10,50,50);
    
    getch();
    closegraph();

    return 0;
}