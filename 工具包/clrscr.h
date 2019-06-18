#ifndef CLRSCR_H
#define CLRSCR_H
#include"include.h"
void clrscr(void)
{
    CONSOLE_SCREEN_BUFFER_INFO sbinf;
    int size;
    COORD scrn = {0, 0};
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hStdOut, &sbinf);
    size = (sbinf.srWindow.Right-sbinf.srWindow.Left+1)*
        (sbinf.srWindow.Bottom-sbinf.srWindow.Top+1);
    FillConsoleOutputCharacter(hStdOut, 32, size, scrn, NULL);
}
#endif