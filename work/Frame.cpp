#include "../Header/Frame.h"
#include "../Header/DataSet.h"
#include "../Header/ConsoleInterface.h"
#include <iostream>

extern DWORD ScreenWide;
extern DWORD ScreenDeep;
int Left_Line;
int Down_Line;
void Frame_Only_Side(){
	gotoxy(0,0);
	for(int i = 0 ; i < ScreenDeep ; i++){
		for(int j = 0 ; j < ScreenWide ; j++){
			if(!i || !j || i == ScreenDeep-1 || j == ScreenWide-1 )	
				std::cout << "#";
			else
				std::cout << " ";
		}
	}
	gotoxy(0,0);
}
void Frame_Pick_Mode(){
	gotoxy(0,0);
	Left_Line = ScreenWide /4;
	Down_Line = ScreenDeep *3 /4;
	for(int i = 0 ; i < ScreenDeep ; i++){
		for(int j = 0 ; j < ScreenWide ; j++){
			if(!i || !j || i == ScreenDeep-1 || j == ScreenWide-1 || (j == Left_Line && i <= Down_Line) || i == Down_Line )	
				std::cout << "#";
			else
				std::cout << " ";
		}
	}
	gotoxy(0,0);
	
}
