#include <graphics.h>
#include <alloc.h>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

void drawGraph(double *argument, double *result, unsigned size, double scaleX, double scaleY, unsigned skipX, unsigned skipY)
{
	int i;
	unsigned x1, x2, y1, y2;
	setlinestyle(0, 0, 3);
	setcolor(RED);
	for (i = 1; i < size; i++)
	{
		x1 = (unsigned)(argument[i-1]*scaleX);
		x2 = (unsigned)(argument[i]*scaleX);
		y1 = getmaxy()-(unsigned)(result[i-1]*scaleY);
		y2 = getmaxy()-(unsigned)(result[i]*scaleY);
		line(x1-skipX, y1+skipY, x2-skipX, y2+skipY);
	}
	return;
}

void drawField(double *argument, double *result, const unsigned size, double scaleX, double scaleY, unsigned clipoff)
{
	int i, x, y, inc = 8;
	char text[8];

	setcolor(GREEN);
	line(clipoff, getmaxy()-clipoff, clipoff, clipoff-15);
	line(clipoff, getmaxy()-clipoff, getmaxx()-clipoff+15, getmaxy()-clipoff);

	setlinestyle(3, 0, 1);
	for (i = 0; i <= inc; i++)
	{
		x = (int)((argument[size-1]-argument[0])/inc*i*scaleX);
		y = (int)((result[size-1]-result[0])/inc*i*scaleY);

		setcolor(LIGHTGRAY);
		line(x+clipoff, getmaxy()-clipoff+5, x+clipoff, clipoff-15);
		line(clipoff-5, getmaxy()-y-clipoff, getmaxx()-clipoff+15, getmaxy()-y-clipoff);

		setcolor(WHITE);
		sprintf(text, "%.2f", (argument[size-1]-argument[0])/inc*i+argument[0]);
		outtextxy(x+16, getmaxy()-clipoff+5, text);
		sprintf(text, "%.2f", (result[size-1]-result[0])/inc*i+result[0]);
		outtextxy(clipoff+3, getmaxy()-y-clipoff-11, text);
	}
	return;
}

void drawMaxValueWindow(double *result, const unsigned size)
{
	unsigned i;
	double maximum;
	char text[30];

	setviewport(120, 40, 360, 80, 1);
	maximum = result[0];
	for (i = 1; i < size; i++)
		if (result[i] > maximum) maximum = result[i];
	setcolor(WHITE);
	setlinestyle(0, 0, 1);
	setfillstyle(SOLID_FILL, DARKGRAY);
	rectangle(0, 0, 239, 39);
	floodfill(1, 1, WHITE);
	sprintf(text, "Maximum value is %f", maximum);
	outtextxy(20, 18, text);
}

int main()
{
	const double startPoint = 3*M_PI/2, endPoint = 18*M_PI, step = M_PI/8;
	const unsigned size = (unsigned)((endPoint-startPoint)/step) + 1;
	double *argument, *result, maximum;
	int i, gD, gM;
	unsigned scaleX, scaleY, skipX, skipY, clipoff = 30;

	detectgraph(&gD, &gM);
	initgraph(&gD, &gM, "C:\\BGI");
	if (graphresult() != grOk) return 255;

	argument = (double*)malloc(size*sizeof(double));
	result = (double*)malloc(size*sizeof(double));

	argument[0] = startPoint;
	result[0] = pow(cos(argument[0]/2),2)+sqrt(argument[0]);

	for (i = 1; i<size; i++)
	{
		argument[i] = argument[i-1]+step;
		result[i] = pow(cos(argument[i]/2),2)+sqrt(argument[i]);
	}
	scaleX = (getmaxx()-2*clipoff)/(endPoint-startPoint);
	scaleY = (getmaxy()-2*clipoff)/(result[size-1]-result[0]);
	skipX = (unsigned)(argument[0]*scaleX) - clipoff;
	skipY = (unsigned)(result[0]*scaleY) - clipoff;

	drawGraph(argument, result, size, scaleX, scaleY, skipX, skipY);
	drawField(argument, result, size, scaleX, scaleY, clipoff);
	drawMaxValueWindow(result, size);

	getch();

	free(argument);
	free(result);
	closegraph();
	return 0;
}