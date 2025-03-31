#include <iostream>
#include <stdlib.h>
#include <graphics.h>
#include <ctype.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <stdio.h>

using namespace std;

int x1brick[50];
int x2brick[50];
int ybrick[5];
int destruction[5][10];
int line1 = 0, line2 = 0, line3 = 0, line4 = 0, line5 = 0;
int checkcollision(int &xc, int &yc, int &r);
void menuScreen();
int beginGame();
void bricks();
void gameOver(int veriebl);

int main()
{
    int gd = DETECT, gm; // ignore for now

    initwindow(1500, 780, "Brick Breaker"); // game window

    menuScreen();

    getch();

    return 0;
}

void menuScreen()
{
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
    outtextxy(50, 50, "A warm welcome from Harshil");

    setcolor(YELLOW);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 6);
    outtextxy(560, 300, "Brick Breaker");

    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 6);
    outtextxy(660, 370, "Game");

    setcolor(WHITE);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
    outtextxy(610, 600, "Press SPACE key to start");

    char start = getch();
    if (start == 32)
    {
        cleardevice();
    }

    bricks();
    beginGame();
}

void bricks()
{
    int brickColor[5] = {CYAN, GREEN, RED, BROWN, BLACK};

    int x = 20, y = 20;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            delay(10);
            setcolor(brickColor[i]);
            rectangle(x, y, x + 140, y + 50);
            x1brick[j] = x;
            x2brick[j] = x + 140;
            x += 145;
        }

        ybrick[i] = y;
        x = 20;
        y += 55;
    }
}

void gameOver(int veriebl)
{
    delay(100);
    setcolor(CYAN);
    settextstyle(BOLD_FONT, HORIZ_DIR, 7);
    outtextxy(500, 300, "GAME OVER :(");

    char scores[10];
    itoa(veriebl, scores, 10);

    delay(100);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 4);
    outtextxy(650, 450, "Score: ");
    outtextxy(780, 450, scores);

    delay(100);
    setcolor(WHITE);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
    outtextxy(530, 600, "Press SPACE key to play again!");

    int c = getch();
    if (c == 32) // SPACE
    {
        cleardevice();
        menuScreen();
    }
}
int beginGame()
{
    setcolor(9);
    int x = 0, y = 600;
    rectangle(x, y, x + 100, y + 4); // Paddle

    setcolor(9);
    int xc = 20, yc = 450, r = 10;
    circle(xc, yc, r); // Ball

    char cuntrol;
    int m = 5, n = 5, temp = 0;

    while (true)
    {
        delay(30);
        setcolor(BLACK);
        circle(xc, yc, r);

        if (kbhit()) // control paddle
        {
            cuntrol = getch();
            if (cuntrol == KEY_LEFT)
            {
                if (x > 30)
                {
                    delay(1);
                    setcolor(BLACK);
                    rectangle(x, y, x + 100, y + 4);
                    x -= 40;
                    setcolor(LIGHTBLUE);
                    rectangle(x, y, x + 100, y + 4);
                }
            }
            if (cuntrol == KEY_RIGHT)
            {
                if (x < 1380)
                {
                    delay(1);
                    setcolor(BLACK);
                    rectangle(x, y, x + 100, y + 4);
                    x += 40;
                    setcolor(LIGHTBLUE);
                    rectangle(x, y, x + 100, y + 4);
                }
            }
        }

        if (xc >= getmaxx() - r) // ball is at right-end
        {
            m = -5;
        }
        if (xc <= r) // ball is left-end
        {
            m = 5;
        }
        if (yc <= r) // ball is at the top
        {
            n = 5;
        }
        if ((yc >= (y - r)) && (xc >= x) && (xc <= (x + 100)))
        {
            n = -5;
        }
        if (yc >= y)
        {
            cleardevice();
            gameOver(temp);
            return 0;
        }

        xc += m;
        yc += n;

        setcolor(LIGHTGRAY);
        circle(xc, yc, r);

        int veriebl = 0;
        char scores[10];

        int baka = checkcollision(xc, yc, r);

        if (baka == 1)
        {
            n = 5;
            temp++;

            // veriebl++;
            // char scores[10];

            itoa(temp, scores, 10);
            settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
            setcolor(WHITE);
            outtextxy(100, 600, scores);
        }
    }
}

int checkcollision(int &xc, int &yc, int &r)
{
    int tempo = -1;

    for (int i = 0; i < 10; i++)
    {
        if (xc > x1brick[9])
        {
            tempo = x1brick[9];
            break;
        }
        if (xc > x1brick[i])
        {
            if (xc < x2brick[i] + 50)
            {
                tempo = x1brick[i];
                break;
            }
        }
        if (xc < x2brick[0])
        {
            tempo = x1brick[0];
            break;
        }
    }

    if ((yc - r) <= ybrick[1])
    {
        for (int i = 0; i < 10; i++)
        {
            if (destruction[0][i] == tempo)
            {
                return 0;
            }
        }

        setcolor(BLACK);
        rectangle(tempo, ybrick[0], tempo + 140, ybrick[0] + 50);

        destruction[0][line1] = tempo;
        line1++;

        return 1;
    }
    else if ((yc - r) <= ybrick[2] && (yc - r) >= ybrick[1])
    {
        for (int i = 0; i < 10; i++)
        {
            if (destruction[1][i] == tempo)
            {
                return 0;
            }
        }
        setcolor(BLACK);
        rectangle(tempo, ybrick[1], tempo + 140, ybrick[1] + 50);

        destruction[1][line2] == tempo;
        line2++;

        return 1;
    }

    else if ((yc - r) <= ybrick[3] && (yc - r) >= ybrick[2])
    {
        for (int i = 0; i < 10; i++)
        {
            if (destruction[2][i] == tempo)
            {
                return 0;
            }
        }

        setcolor(BLACK);
        rectangle(tempo, ybrick[2], tempo + 140, ybrick[2] + 50);

        destruction[2][line3] = tempo;
        line3++;

        return 1;
    }

    else if ((yc - r) <= ybrick[4] && (yc - r) >= ybrick[3])
    {
        for (int i = 0; i < 10; i++)
        {
            if (destruction[3][i] == tempo)
            {
                return 0;
            }
        }
        setcolor(BLACK);
        rectangle(tempo, ybrick[3], tempo + 140, ybrick[3] + 50);

        destruction[3][line4] = tempo;
        line4++;

        return 1;
    }

    else if ((yc - r) <= ybrick[5] && (yc - r) >= ybrick[4])
    {
        for (int i = 0; i < 10; i++)
        {
            if (destruction[4][i] == tempo)
            {
                return 0;
            }
            setcolor(BLACK);
            rectangle(tempo, ybrick[4], tempo + 140, ybrick[4] + 50);

            destruction[4][line5] = tempo;
            line5++;

            return 1;
        }
    }

    else
    {
        return 0;
    }
}
