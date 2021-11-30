#include <graphics.h>
#include <alloc.h>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

void drawFunction(double *X, double *Y, unsigned size, double coefficientX, double coefficientY, unsigned passX, unsigned passY, double start)
{
    int i;
    unsigned x1, x2, y1, y2;
    setlinestyle(0, 0, 3);
    setcolor(RED);
    for (i = 1; i < size; i++)
    {
        x1 = (unsigned)(X[i-1]*coefficientX);
        x2 = (unsigned)(X[i]*coefficientX);
        y1 = getmaxy()-(unsigned)(Y[i-1]*coefficientY);
        y2 = getmaxy()-(unsigned)(Y[i]*coefficientY);

        if (X[i-1] < start) continue;

        line(x1-passX, y1+passY, x2-passX, y2+passY);
    }
    return;
}


void drawCoordinatePlane(double *X, double *Y, const unsigned size, double coefficientX, double coefficientY, unsigned border){
    int i, x, y, interval = 10;
    char text[30];
    setcolor(LIGHTGRAY);
    line(border, getmaxy()-border, border, border-15);
    line(border, getmaxy()-border, getmaxx()-border+15, getmaxy()-border);

    setlinestyle(3, 0, 1);
    for (i = 0; i <= interval; i++)
    {

        x = (int)((X[size-1]-X[0])/interval*i*coefficientX);
        y = (int)((Y[size-1]-Y[0])/interval*i*coefficientY);

        line(x+border, getmaxy()-border+5, x+border, border-15);
        line(border-5, getmaxy()-y-border, getmaxx()-border+15, getmaxy()-y-border);

        sprintf(text, "%.2f", (X[size-1]-X[0])/interval*i+X[0]);
        outtextxy(x+16, getmaxy()-border+5, text);
        sprintf(text, "%.2f", (Y[size-1]-Y[0])/interval*i+Y[0]);
        outtextxy(border+3, getmaxy()-y-border-11, text);
    }
}

void drawMaxValueOfFunction(double *Y, const unsigned size)
{
    unsigned i;
    double maximum;
    char text[30];

    setviewport(120, 40, 360, 80, 1);
    maximum = Y[0];
    for (i = 1; i < size; i++)
        if (Y[i] > maximum) maximum = Y[i];
    setcolor(YELLOW);
    setlinestyle(0, 0, 1);
    setfillstyle(SOLID_FILL, DARKGRAY);
    rectangle(0, 0, 239, 39);
    floodfill(1, 1, YELLOW);
    sprintf(text, "Maximum value is %f", maximum);
    outtextxy(20, 18, text);
}

int main()
{
    const double start = 3*M_PI/2, end = 15*M_PI, step = M_PI/8;
    const unsigned size = (unsigned)(end/step) + 1;
    double *X, *Y;
    int i, graphDriver, graphMode;
    unsigned coefficientX, coefficientY, passX, passY, border = 20;

    detectgraph(&graphDriver, &graphMode);
    initgraph(&graphDriver, &graphMode, "C:\\BGI");
    if (graphresult() != grOk) {
        char error[15];
        sprintf(error,"Graphic error.");
        outtextxy(1, 1, error);
        return -1;
    }

    X = (double*)malloc(size*sizeof(double));
    Y = (double*)malloc(size*sizeof(double));

    X[0] = 0;
    Y[0] = pow(sin(X[0]/2),2)+sqrt(X[0]);

    for (i = 1; i < size; i++)
    {
        X[i] = X[i-1]+step;
        Y[i] = pow(sin(X[i]/2),2)+sqrt(X[i]);
    }
    coefficientX = (getmaxx()-2*border)/end;
    coefficientY = (getmaxy()-2*border)/(Y[size-1]-Y[0]);
    passX = (unsigned)(X[0]*coefficientX) - border;
    passY = (unsigned)(Y[0]*coefficientY) - border;

    drawFunction(X, Y, size, coefficientX, coefficientY, passX, passY, start);
    drawCoordinatePlane(X, Y, size, coefficientX, coefficientY, border);
    drawMaxValueOfFunction(Y, size);

    getch();

    free(X);
    free(Y);
    closegraph();
    return 0;
}