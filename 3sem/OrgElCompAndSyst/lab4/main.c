#include <conio.h>
#include <dos.h>

#define EXIT 113
#define DOWN 72
#define LEFT 75
#define UP 80
#define RIGHT 77

int getSymbol()
{
    union REGS reg;
    reg.h.ah = 0x08;
    int86(0x21, &reg, &reg);
    return reg.h.al;
}

int main(){
    int i, x1, y1, y2, x2, x, y;
    int flagExit = 1;
    char symbol;
    x1 = 10; y1 = 5; x2 = 70; y2 = 15;
    x = 1; y = 1;

    clrscr();
    window(x1, y1, x2, y2);
    gotoxy(x, y);
    textcolor(RED);

    while (flagExit) {
        symbol = getSymbol();
        switch (symbol) {
            case DOWN:
                if (y > 1) y--;
                break;
            case LEFT:
                if (x > 1) x--;
                break;
            case UP:
                if (y <= 10) y++;
                break;
            case RIGHT:
                if (x <= 60) x++;
                break;
            case EXIT:
                flagExit = 0;
                break;
            default: break;
        }
        clrscr();
        gotoxy(x, y);
        cprintf("@");
    }
}