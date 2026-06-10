#include <stdio.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

void initializeCanvas()
{
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas()
{
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}
void drawRectangle(int x,int y,int width,int height)
{
    for(int j=x;j<x+width;j++)
    {
        canvas[y][j]='*';
        canvas[y+height-1][j]='*';
    }

    for(int i=y;i<y+height;i++)
    {
        canvas[i][x]='*';
        canvas[i][x+width-1]='*';
    }
}

#include <stdlib.h>

void drawLine(int x1,int y1,int x2,int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int steps = (dx > dy) ? dx : dy;

    float xInc = (float)(x2 - x1) / steps;
    float yInc = (float)(y2 - y1) / steps;

    float x = x1;
    float y = y1;

    for(int i=0;i<=steps;i++)
    {
        if((int)x >= 0 && (int)x < COLS &&
           (int)y >= 0 && (int)y < ROWS)
        {
            canvas[(int)y][(int)x] = '*';
        }

        x += xInc;
        y += yInc;
    }
}

int main()
{
    initializeCanvas();
   
    drawLine(0,0,39,19);
    displayCanvas();

    return 0;
}