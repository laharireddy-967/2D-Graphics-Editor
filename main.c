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

int main()
{
    initializeCanvas();
    drawRectangle(5,5,10,5);
    displayCanvas();

    return 0;
}