#include "./header/ConsoleInterface.h"
#include "./header/Mode_PickNum.h"
#include "./header/DataSet.h"
#include "./header/Frame.h"

DWORD ScreenWide,ScreenDeep;	//螢幕寬 螢幕長
static int WideIndention = 10;	//螢幕寬縮 
static int DeepIndention = 5;	//螢幕長縮 
static int Head_Of_Line = 1;	//行開頭 
static int Head_Of_Row  = 1;	//列開頭


int main(){	
	
	SetConsoleTitle("314抽籤程式");
	_GetLargestConsoleWindowSize( ScreenWide , ScreenDeep );
	ScreenWide -= WideIndention;
	ScreenDeep -= DeepIndention;
	SetConsoleSize( ScreenWide , ScreenDeep );
	
	//cout << ScreenWide << " " << ScreenDeep <<endl;
	//system("IF NOT EXIST ./test ECHO Yes");
	
	Frame_Only_Side();
	coutxy_no_newline( ScreenWide/2-6 , ScreenDeep/2 , "請按Enter繼續"); 
	getchar();
	
	Mode_PickNum();
	clrscr();
	
	Frame_Only_Side();
	coutxy_no_newline( ScreenWide/2-6 , ScreenDeep/2 , "請按Enter結束"); 
	getchar();

	return 0;
	
}
