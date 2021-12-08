#include <conio.h>
#include <dos.h>

#define EXIT 113
#define LEFT 75
#define RIGHT 77

int getSymbol(){
    union REGS reg;
    reg.h.ah = 0x08;
    int86(0x21, &reg, &reg);
    return reg.h.al;
}

void printHero(int xHero, int yHero) {
    textcolor(BLUE);
    gotoxy(xHero, yHero); cprintf("@");
    gotoxy(xHero + 1, yHero); cprintf(")");
    gotoxy(xHero - 1, yHero); cprintf("(");
    gotoxy(xHero, yHero - 1); cprintf("_");
}

void printEnemy(int xEnemy, int yEnemy) {
    if (yEnemy < 1) return;
    textcolor(RED);
    gotoxy(xEnemy, yEnemy); cprintf("z");
    gotoxy(xEnemy+1, yEnemy); cprintf("z");
    gotoxy(xEnemy, yEnemy+1); cprintf("z");
    gotoxy(xEnemy+1, yEnemy+1); cprintf("z");
}

int main(){
    int i, x1, y1, y2, x2, xHero, yHero, x, y, lives;
    int flagExit = 1;
    char symbol;
    int leftTopX, leftTopY, rightTopX, rightTopY, leftDownX, leftDownY, rightDownX, rightDownY;
    int xEnemy[2];
    int yEnemy[2];
    int rightRun, leftRun;
    x1 = 20; y1 = 3; x2 = 60; y2 = 23;

    leftTopX = 1; leftTopY = 1;
    leftDownX = 1; leftDownY = y2 - y1 + 1;
    rightTopX = x2 - x1 + 1; rightTopY = 1;
    rightDownX = x2 - x1 + 1; rightDownY = y2 - y1 + 1;

    clrscr();
    window(x1, y1, x2, y2);

    textbackground(WHITE);
    clrscr();

    xHero = rightDownX-2; yHero = rightDownY-1;

    lives = 3;

    xEnemy[0] = 3;
    yEnemy[0] = 1;
    xEnemy[1] = rightDownX-3;
    yEnemy[1] =  yEnemy[1] - (rand() % 15) - 5;

    while (flagExit) {
        clrscr();

        printHero(xHero,yHero);

        if (kbhit()) {
            symbol = getSymbol();

            switch (symbol) {
                case LEFT:
                    if (xHero > leftTopX+2) leftRun = 1;
                    break;
                case RIGHT:
                    if (xHero < rightTopX-2) rightRun = 1;
                    break;
                case EXIT:
                    flagExit = 0;
                    break;
                default: break;
            }
        }

        // move hero by horisontal
        if ( (rightRun == 1) && (leftRun == 1) ){
            if (xHero > rightTopX/2){
                leftRun = 0;
                xHero += 3;
            }
            else{
                rightRun = 0;
                xHero -= 3;
            }
        }
        else if ( (rightRun == 1) && (xHero < (rightTopX-2)) ){
            xHero += 4;
            if (xHero >= (rightTopX-2)) xHero = (rightTopX-2);
        }
        else if( (rightRun == 1) && (xHero >= (rightTopX-2)) ) {
            rightRun = 0;
        }
        else if ( (leftRun == 1) && (xHero > (leftTopX+2)) ) {
            xHero -= 4;
            if (xHero <= (leftTopX+2)) xHero = (leftTopX+2);
        }
        else if ( (leftRun == 1) && (xHero <= (leftTopX+2)) ){
            leftRun = 0;
        }


        // move enemy1
        if (yEnemy[0] < leftDownY-1)
            printEnemy(xEnemy[0], yEnemy[0]);
        else
            yEnemy[0] = 1;
        yEnemy[0]++;


        // move enemy2
        if (yEnemy[1] < leftDownY-1)
            printEnemy(xEnemy[1], yEnemy[1]);
        else
            yEnemy[1] = 1 - (rand() % 15) - 5;
        yEnemy[1]++;


        if ( ( ((xHero-1) == (xEnemy[0])) && (yHero == yEnemy[0]+1) )
             || ( ((xHero) == (xEnemy[0])) && (yHero == yEnemy[0]+1) )
             || ( ((xHero+1) == (xEnemy[0])) && (yHero == yEnemy[0]+1) )

             || ( ((xHero-1) == (xEnemy[0]+1)) && (yHero == yEnemy[0]+1) )
             || ( ((xHero) == (xEnemy[0]+1)) && (yHero == yEnemy[0]+1) )
             || ( ((xHero+1) == (xEnemy[0]+1)) && (yHero == yEnemy[0]+1) )

             || ( ((xHero-1) == (xEnemy[0])) && (yHero == yEnemy[1]+1) )
             || ( ((xHero) == (xEnemy[0])) && (yHero == yEnemy[1]+1) )
             || ( ((xHero+1) == (xEnemy[0])) && (yHero == yEnemy[1]+1) )

             || ( ((xHero-1) == (xEnemy[1]+1)) && (yHero == yEnemy[1]+1) )
             || ( ((xHero) == (xEnemy[1]+1)) && (yHero == yEnemy[1]+1) )
             || ( ((xHero+1) == (xEnemy[1]+1)) && (yHero == yEnemy[1]+1) )

                ) {
            lives--;
        }


        textcolor(RED);
        gotoxy(rightDownX/2 - 3, 5);
        cprintf("lives = %d", lives);

        if (lives == 0) {
            flagExit = 0;
            clrscr();
            textcolor(RED);
            gotoxy(rightDownX/2 - 3, rightDownY/2); cprintf("GAME OVER");
            gotoxy(rightDownX/2 - 3, rightDownY/2 + 1); cprintf("YOU LOSE");

        }
        delay(75);
    }
}