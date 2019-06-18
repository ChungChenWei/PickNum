#include"../Header/ConsoleInterface.h" 
#include<iostream>
#include<string>
#include<windows.h>

void _SetConsoleTitle(const char* title){
        SetConsoleTitle(title); 
}
void _GetConsoleTitle(char* title, DWORD nSize){
        GetConsoleTitle(title, nSize);
}
void gotoxy(int x, int  y){
        COORD point;
        point.X = x, point.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}
void coutxy(int x, int y, std::string content){
	gotoxy(x, y);
	std::cout << content;
	gotoxy(x, y+1);
}
void coutxy_no_newline(int x, int y, std::string content){
	gotoxy(x, y);
	std::cout << content;
}
void getxy(int &x, int &y){
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        x = csbi.dwCursorPosition.X;
        y = csbi.dwCursorPosition.Y;
}
void clrscr_Bad(void){
    CONSOLE_SCREEN_BUFFER_INFO sbinf;
    int size;
    COORD scrn = {0, 0};
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hStdOut, &sbinf);
    size = (sbinf.srWindow.Right-sbinf.srWindow.Left+1)*
        (sbinf.srWindow.Bottom-sbinf.srWindow.Top+1);
    FillConsoleOutputCharacter(hStdOut, 32, size, scrn, NULL);
}
void clrscr(void){system("CLS");}
BOOL SetConsoleSize(int W, int H){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cor;
    cor.X = W;
    cor.Y = 1000;
    SetConsoleScreenBufferSize(hConsole,cor);
    CONSOLE_SCREEN_BUFFER_INFO oConsoleBufferInfo;
    GetConsoleScreenBufferInfo(hConsole,&oConsoleBufferInfo);
    cor.Y = H;
    /*
    printf("%d %d %d %d\n",
	 oConsoleBufferInfo.srWindow.Left,
     oConsoleBufferInfo.srWindow.Top,
     oConsoleBufferInfo.srWindow.Right,
     oConsoleBufferInfo.srWindow.Bottom);
    */
	oConsoleBufferInfo.srWindow.Right=cor.X-1;
	oConsoleBufferInfo.srWindow.Left=0;
	oConsoleBufferInfo.srWindow.Top=0;
	oConsoleBufferInfo.srWindow.Bottom=cor.Y-1;
	/*
	printf("%d %d %d %d\n",
	 oConsoleBufferInfo.srWindow.Left,
     oConsoleBufferInfo.srWindow.Top,
     oConsoleBufferInfo.srWindow.Right,
     oConsoleBufferInfo.srWindow.Bottom);
    */
	SetConsoleWindowInfo(hConsole,true,&oConsoleBufferInfo.srWindow); // 改變console 視窗大小 
}
void GetConsoleWindowSize(DWORD &W, DWORD &H){
        CONSOLE_FONT_INFO cfi;
        GetCurrentConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
        W = cfi.dwFontSize.X;
        H = cfi.dwFontSize.Y;
}
void _GetLargestConsoleWindowSize(DWORD &W, DWORD &H){
        COORD c = GetLargestConsoleWindowSize(GetStdHandle(STD_OUTPUT_HANDLE));
        W = c.X;
        H = c.Y;
}
