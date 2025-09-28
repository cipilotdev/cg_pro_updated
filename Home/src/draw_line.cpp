#include <stdio.h> 
#include <stdlib.h> 
#include <conio.h>
#include <graphics.h>

int x_mid, y_mid; // Global declaration variable
float xst_new, yst_new, xto_new, yto_new;

struct coordinate{
    int x;
    int y;
}coor_st, coor_to;

void convert_coor(int x_st, int y_st, int x_to, int y_to)
{
    xst_new = float(x_st) + float(x_mid);
    yst_new = float(y_mid) - float(y_st);
    xto_new = float(x_to) + float(x_mid);
    yto_new = float(y_mid) - float(y_to);
    printf("Xst: %f; Yst: %f\n",xst_new,  yst_new);
    printf("Xto: %f; Yto: %f\n", xto_new,  yto_new);
    
}

void m_smaller(float x, float y, int x_to, float m, float c)
{    
    do
    {
        x = x + 1;
        y = (m * x) + c;
        putpixel(x , y, WHITE);
    }while(x<=x_to);
}

void m_larger(float x, float y, int y_to, float m, float c)
{
    do
    {
        y = y + 1;
        x = (y - c) / m;
        putpixel(x , y, WHITE);
    }while(y<=y_to);
    
}

void draw_equation(int x_st, int y_st, int x_to, int y_to)
{
    float x, y, m, c;
    int delta_x, delta_y;
    m = ((float)y_to - (float)y_st) / ((float)x_to - (float)x_st);
    c = (float)y_st - (m * (float)x_st); 
    convert_coor(x_st, y_st, x_to, y_to);
    x = x_st, y = y_st;
    putpixel(x + x_mid, y_mid - y, WHITE);
    if (m < 1)
        m_smaller(x, y, x_to, m, c);
    else
        m_larger(x, y, y_to, m, c);
}

void draw_bresenham(int x_st, int y_st, int x_to, int y_to)
{
    int delta_x, delta_y, xtemp, ytemp, p;
    int x, y, i;   
    delta_x = x_to - x_st;
    delta_y = y_to - y_st;

    if (delta_x >= 0) xtemp = 1;
    else xtemp = -1;

    if (delta_y >= 0) ytemp = 1; 
    else ytemp = -1;

    x = x_st, y = y_st;
    putpixel(x + x_mid, y_mid - y, WHITE);
    i = 0;
    if (abs(delta_y) < abs(delta_x))
    {
        p = (2 * abs(delta_y)) - abs(delta_x);
        do
        {
            if (p < 0)
            {
                x = x + xtemp;
                p = p + 2 * abs(delta_y);                
            }
            else
            {
                x = x + xtemp;
                y = y + ytemp;
                p = p + 2 * abs(delta_y) - 2 * abs(delta_x);
            }
            putpixel(x + x_mid, y_mid - y, WHITE);
            i++;
        }while(i<=abs(delta_x));
    }
    else
    {
        p = (2 * abs(delta_x)) - abs(delta_y);
        do
        {
            if (p < 0)
            {
                y = y + ytemp;
                p = p + 2 * abs(delta_x);
            }
            else
            {
                x = x + xtemp;
                y = y + ytemp;
                p = p + 2 * abs(delta_x) - 2 * abs(delta_y);
            }
            putpixel(x + x_mid, y_mid - y, WHITE);
            i++;
        }while(i<=abs(delta_y));
    }
}

void draw_dda(int x_st, int y_st, int x_to, int y_to)
{
    int delta_x, delta_y, dda;
    float x_inc, y_inc, x, y, i;    
    
    delta_x = x_to - x_st;
    delta_y = y_to - y_st;

    if (abs(delta_y) < abs(delta_x)) 
        dda = abs(delta_x);
    else 
        dda = abs(delta_y);
    x_inc = delta_x / (float)dda;
    y_inc = delta_y / (float)dda;

    x = x_st, y = y_st;
    putpixel(x + x_mid, y_mid - y , WHITE); 
    i = 0;
    do
    {
        x = x + x_inc;
        y = y + y_inc;
        printf("X: %f; Y: %f\n", x + x_mid,  y_mid - y);
        putpixel(x + x_mid, y_mid - y, WHITE);
        i++;
    }while(i<=dda);
}

int main()
{
    int gm, gd = DETECT;
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; 
    initgraph(&gd, &gm, data);
    cleardevice();
    int xmax = getmaxx(), ymax = getmaxy();
    int choice;
    
    //coding graphics
    x_mid = xmax/2;
    y_mid = ymax/2;

    setcolor(RED);
    line(0, y_mid, xmax, y_mid);
    line(x_mid, 0, x_mid, ymax);

    printf("Enter start coordinate: "); scanf("%d %d", &coor_st.x, &coor_st.y);
    printf("Enter end coordinate: "); scanf("%d %d", &coor_to.x, &coor_to.y);
    printf("List of line algorithm:\n");
    printf("\t1. DDA\n");
    printf("\t2. Bresenham\n");
    printf("\t3. Equation\n");
    printf("Which algorithm do you want to use: "); scanf("%d", &choice);

    // Panggil prosedur dda
    switch (choice) {
        case 1:
            draw_dda(coor_st.x, coor_st.y, coor_to.x, coor_to.y);
            break;
        case 2:
            draw_bresenham(coor_st.x, coor_st.y, coor_to.x, coor_to.y);
            break;
        case 3:
            draw_equation(coor_st.x, coor_st.y, coor_to.x, coor_to.y);
            break;
        case 4:
            draw_dda(coor_st.x, coor_st.y, coor_to.x, coor_to.y);
            break;
        default:
            printf("Wrong choice\n");
            break;
    }

    getch();
    closegraph();

    return 0;
}

