#include "./header/ConsoleInterface.h"
#include "./header/Mode_PickNum.h"
#include "./header/DataSet.h"
#include "./header/Frame.h"

DWORD ScreenWide,ScreenDeep;	//�ù��e �ù���
static int WideIndention = 10;	//�ù��e�Y 
static int DeepIndention = 5;	//�ù����Y 
static int Head_Of_Line = 1;	//��}�Y 
static int Head_Of_Row  = 1;	//�C�}�Y


int main(){	
	
	SetConsoleTitle("314���ҵ{��");
	_GetLargestConsoleWindowSize( ScreenWide , ScreenDeep );
	ScreenWide -= WideIndention;
	ScreenDeep -= DeepIndention;
	SetConsoleSize( ScreenWide , ScreenDeep );
	
	//cout << ScreenWide << " " << ScreenDeep <<endl;
	//system("IF NOT EXIST ./test ECHO Yes");
	
	Frame_Only_Side();
	coutxy_no_newline( ScreenWide/2-6 , ScreenDeep/2 , "�Ы�Enter�~��"); 
	getchar();
	
	Mode_PickNum();
	clrscr();
	
	Frame_Only_Side();
	coutxy_no_newline( ScreenWide/2-6 , ScreenDeep/2 , "�Ы�Enter����"); 
	getchar();

	return 0;
	
}
