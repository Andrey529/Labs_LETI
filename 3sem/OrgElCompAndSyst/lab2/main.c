#define UP 0x07

#include <conio.h>
#include <dos.h>

void printText(numberOfFontColor){
    switch (numberOfFontColor) {
        case 0: cprintf("BLACK font"); break;
        case 1: cprintf("BLUE font"); break;
        case 2: cprintf("GREEN font"); break;
        case 3: cprintf("CYAN font"); break;
        case 4: cprintf("RED font"); break;
        case 5: cprintf("MAGENTA font"); break;
        case 6: cprintf("BROWN font"); break;
        case 7: cprintf("LIGHTGRAY font"); break;
        case 8: cprintf("DARKGRAY font"); break;
        case 9: cprintf("LIGHTBLUE font"); break;
        case 10: cprintf("LIGHTGREEN font"); break;
        case 11: cprintf("LIGHTCYAN font"); break;
        case 12: cprintf("LIGHTRED font"); break;
        case 13: cprintf("LIGHTMAGENTA font"); break;
        case 14: cprintf("YELLOW font"); break;
        case 15: cprintf("WHITE font"); break;
    }
}

void scroll(int lines, char attr){
    union REGS r;
    r.h.ah = UP;
    r.h.al = lines;
    r.h.cl = 9;
    r.h.ch = 4;
    r.h.dl = 69;
    r.h.dh = 14;
    r.h.bh = attr;
    int86(0x10, &r, &r);
}

int main(){
    int i, x1, y1, y2, x2, numberOfFontColor, numberOfBackground, lines;
    x1 = 10; y1 = 5; x2 = 70; y2 = 15;
    lines = 1;
    numberOfFontColor = 0; numberOfBackground = 0;
    clrscr();
    window(x1, y1, x2, y2);


    for (numberOfFontColor = 0; numberOfFontColor < 16; numberOfFontColor++){
        textcolor(numberOfFontColor);

        for (numberOfBackground = 0; numberOfBackground < 8; numberOfBackground++){
            if(numberOfFontColor == numberOfBackground) continue;
            textbackground(numberOfBackground);

            if(!(numberOfFontColor == 0 && numberOfBackground == 0))
                cprintf("\r\n");

            scroll(lines+1,numberOfBackground*17);

            printText(numberOfFontColor);
            cprintf(" and Background color = %d",numberOfBackground);
            clreol();
            gotoxy(1, 1);

            delay(300);
        }
    }
}