#include <stdio.h> //input dan output 
#include <stdlib.h> 
#include <conio.h> //getch()
#include <math.h>
#include <graphics.h>

int x_mid, y_mid;

void bre_line(int xa, int ya, int xb, int yb, int color)
{
    int delta_x = xb - xa;
    int delta_y = yb - ya;
    int xtemp, ytemp;

    if (delta_x >= 0)
        xtemp = 1;
    else
        xtemp = -1;

    if (delta_y >= 0)
        ytemp = 1;
    else
        ytemp = -1;

    delta_x = abs(delta_x);
    delta_y = abs(delta_y);

    int x = xa, y = ya, p, i = 0;
    putpixel(x + x_mid, y_mid - y, color);

    if (delta_y < delta_x)
    {
        p = 2 * delta_y - delta_x;
        while (i <= delta_x)
        {
            if (p < 0) p += 2 * delta_y;
            else { p += 2 * delta_y - 2 * delta_x; y += ytemp; }
            x += xtemp;
            putpixel(x + x_mid, y_mid - y, color);
            i++;
        }
    }
    else
    {
        p = 2 * delta_x - delta_y;
        while (i <= delta_y)
        {
            if (p < 0) p += 2 * delta_x;
            else { p += 2 * delta_x - 2 * delta_y; x += xtemp; }
            y += ytemp;
            putpixel(x + x_mid, y_mid - y, color);
            i++;
        }
    }
}

float degressToRadians(float angle)
{
    return angle * M_PI / 180;
}

void triangle(int xa, int ya, int angle, int sideLen)
{
    int xb = sideLen * cos(degressToRadians(angle - 30)) + xa;
    int yb = sideLen * sin(degressToRadians(angle - 30)) + ya;

    int xc = sideLen * cos(degressToRadians(angle + 30)) + xa;
    int yc = sideLen * sin(degressToRadians(angle + 30)) + ya;

    printf("xa: %d, ya: %d\n", xa, ya);
    printf("xb: %d, yb: %d\n", xb, yb);
    printf("xc: %d, yc: %d\n", xc, yc);

    bre_line(xa, ya, xb, yb,4);
    bre_line(xc, yc, xb, yb,1);
    bre_line(xa, ya, xb, yb,14);
}

void triangle2(int xa, int ya, int xb, int yb, int xc, int yc) {
    bre_line(xa, ya, xb, yb, 4);  // sisi 1: A → B
    bre_line(xb, yb, xc, yc, 1);  // sisi 2: B → C
    bre_line(xc, yc, xa, ya, 14); // sisi 3: C → A
}

void triangle3(int xa, int ya, int angle, int sideLen)
{
    int xb = sideLen * cos(degressToRadians(angle - 30)) + xa;
    int yb = sideLen * sin(degressToRadians(angle - 30)) + ya;

    int xc = sideLen * cos(degressToRadians(angle + 30)) + xa;
    int yc = sideLen * sin(degressToRadians(angle + 30)) + ya;

    bre_line(xa, ya, xb, yb,4);
    bre_line(xc, yc, xb, yb,1);
    // bre_line(xa, ya, xb, yb,14);
    bre_line(xa, ya, xc, yc, 14);
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
    // triangle(10,10,-30.0,100);
    triangle2(10, 20, 100, 50, 50, 150);
    
    getch();
    closegraph();

    return 0;
}