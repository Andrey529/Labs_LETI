#include <conio.h>
#include <dos.h>

#define EXIT 113
#define DOWN 72
#define LEFT 75
#define UP 80
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
    textcolor(RED);
    gotoxy(xEnemy, yEnemy); cprintf("z");
    gotoxy(xEnemy+1, yEnemy); cprintf("z");
    gotoxy(xEnemy, yEnemy+1); cprintf("z");
    gotoxy(xEnemy+1, yEnemy+1); cprintf("z");
}

int main(){
    int i, x1, y1, y2, x2, xHero, yHero, x, y;
    int flagExit = 1;
    char symbol;
    int leftTopX, leftTopY, rightTopX, rightTopY, leftDownX, leftDownY, rightDownX, rightDownY;
    int xEnemy[5];
    int yEnemy[5];
    int side;
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



    for (i = 0; i < 5; i++) {
        srand(time(0));
        side = rand() % 2;
        if (side == 0)
            xEnemy[i] = 3;
        else
            xEnemy[i] = rightDownX;
        yEnemy[i] = 1;
    }

    while (flagExit) {
        clrscr();

        printHero(xHero,yHero);

        if (kbhit()) {
            symbol = getSymbol();
            switch (symbol) {
                case DOWN:
                    if (yHero > leftTopY+1) yHero--;
                    symbol = 0;
                    break;
                case LEFT:
                    if (xHero > leftTopX+2){
                        leftRun = 1;
                    }
                    break;
                case UP:
                    if (yHero < leftDownY-1) yHero++;
                    symbol = 0;
                    break;
                case RIGHT:
                    if (xHero < rightTopX-2) {
                        rightRun = 1;
                    }
                    break;
                case EXIT:
                    flagExit = 0;
                    break;
                default: break;
            }
        }

        if ( (rightRun == 1) && (xHero < (rightTopX-2)) )
            xHero += 3;
        else if( (rightRun == 1) && (xHero >= (rightTopX-2)) )
            rightRun = 0;
        else if ( (leftRun == 1) && (xHero > (leftTopX+2)) )
            xHero -= 3;
        else if ( (leftRun == 1) && (xHero <= (leftTopX+2)) )
            leftRun = 0;


        for (i = 0; i < 5; i++) {
            if (yEnemy[i] < leftDownY-1)
                printEnemy(xEnemy[i], yEnemy[i]);
            else
                yEnemy[i] = 1;
            yEnemy[i]++;
        }

        delay(50);
    }
}