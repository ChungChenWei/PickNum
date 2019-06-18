#ifndef CONSOLE_INTERFACE_H
#define CONSOLE_INTERFACE_H
#include <windows.h>
#include <string>

void _SetConsoleTitle(const char* title);
//void _GetConsoleTitle(char* title, DWORD nSize);
void gotoxy(int x, int y);
void coutxy(int x, int y, std::string content); 
void coutxy_no_newline(int x, int y, std::string content); 
void getxy(int &x, int &y);
void clrscr(void);
BOOL SetConsoleSize(int W, int H);
//void GetConsoleWindowSize(DWORD &W, DWORD &H);
void _GetLargestConsoleWindowSize(DWORD &W, DWORD &H);

#endif
