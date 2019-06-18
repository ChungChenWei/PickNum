#include "../Header/WordGenerator.h"
#include "../Header/ConsoleInterface.h"
#include "../Header/PickNum.h"
#include "../Header/Frame.h"
#include "../Header/DataSet.h"
#include "../Header/Mode_PickNum.h"
#include <string.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

static int Num_Need;
static int Num_Pick;
static int Head_Of_Word_Line ;	//行開頭 
static int Head_Of_Word_Row  ;	//列開頭
static int Head_Of_Topic_Line; 	//行開頭 
static int Head_Of_Topic_Row = 1;	//列開頭
static int Head_Of_Current_Row;		//列開頭
static int Topic_Blank;
static int x,y,nx,ny;
static int People;

static int Num_Out[10000];
static string print;
static bool out[10000];

void Mode_PickNum(){
	Frame_Pick_Mode();
	Word_Informatio();
	Head_Of_Word_Line	= (ScreenWide + Left_Line - Num_X*4 -4) /2;
	Head_Of_Word_Row	= (Down_Line - Num_Y)/2;
	Head_Of_Topic_Line 	= ScreenWide /8 -9;
	Topic_Blank  = (Down_Line) /6 ;
	srandSet();
	
	coutxy_no_newline( Head_Of_Topic_Line , Head_Of_Topic_Row + Topic_Blank*1 , "歡迎使用抽籤程式");
	coutxy_no_newline( Head_Of_Topic_Line , Head_Of_Topic_Row + Topic_Blank*6 , "目前輸出尺寸： 3");
	coutxy_no_newline( Head_Of_Topic_Line , Head_Of_Topic_Row + Topic_Blank*2 , "請輸入最小值 : ");
	getxy(x,y);
	cout << "      ";
	gotoxy( x,y );
//	Num_Min = 1;
	cin >> Num_Min;
	coutxy_no_newline( Head_Of_Topic_Line , Head_Of_Topic_Row + Topic_Blank*3 , "請輸入最大值 : ");
	getxy(x,y);
	cout << "       ";
	gotoxy( x,y );
//	Num_Max = 29;
	cin >> Num_Max;

	loop:
	memset(out,0,sizeof(out));
	People = 0;
	nx = 0;
	Head_Of_Current_Row = ScreenDeep *7 /8;	
	
	coutxy_no_newline( Head_Of_Topic_Line , Head_Of_Topic_Row + Topic_Blank*4 , "請輸入所需數目 : ");
	getxy(x,y);
	cout << "     ";
	gotoxy( x,y );
	cin >> Num_Need;
	
	while( Num_Need-- ){
	if(!(People % Num_Max))	memset(out,0,sizeof(out));
	People ++;
	PickNum( Num_Pick );
	while( out[ Num_Pick ] )	PickNum( Num_Pick );
	if( !out[ Num_Pick ] )		out[ Num_Pick ]=true;
	Num_Out[ People ] = Num_Pick;
	//cout << Num_Pick << endl;
	
	gotoxy( Head_Of_Word_Line , Head_Of_Word_Row );
		if( Num_Pick >= 10){
			WordGenerator( Num_Pick /10);
			gotoxy( Head_Of_Word_Line + 4 + 2*Num_Fac*Num_X , Head_Of_Word_Row);
			WordGenerator( Num_Pick %10);
		}else{
			WordGenerator( 0 );
			gotoxy( Head_Of_Word_Line + 4 + 2*Num_Fac*Num_X , Head_Of_Word_Row);
			WordGenerator( Num_Pick );
		}
		
	if(People == 1 && Num_Need != 1)	getchar(); //暫時性補救 
	
	gotoxy( 2 , ScreenDeep *7 /8 -2 );
	cout << "目前抽出 第 " << People << " 個人";
	if(nx >= ScreenWide -7)	++Head_Of_Current_Row, nx=0;
	gotoxy( 2 + nx +1 ,  Head_Of_Current_Row );
	cout << Num_Out[ People ];
	getxy(nx, ny);
	if( Num_Out[ People ] <10)	nx++;
	getchar();
	
}
	while(1){	//是否繼續 
		coutxy_no_newline( Head_Of_Topic_Line , Head_Of_Topic_Row + Topic_Blank*5 , "是否繼續?(y/n) : ");
		getxy(x, y);
		
		char yn;
		yn = getchar();
		
		if(yn == 'y' || yn == 'Y'){
			coutxy( Head_Of_Topic_Line , Head_Of_Topic_Row + Topic_Blank*5 ,"                  ");
			for(int j = Head_Of_Word_Row ; j < Down_Line-1 ; j++){
				gotoxy( Left_Line +1 , j);
				for(int i = Left_Line+1 ; i < ScreenWide-1 ; i++) cout << " " ;
			}
			for(int j = ScreenDeep *7 /8 -2 ; j < ScreenDeep-1 ; j++){
				gotoxy( 2 , j);
				for(int i = 2 ; i < ScreenWide-1 ; i++) cout << " " ;
			}
			goto loop;
		}
		else if(yn == 'n' || yn == 'N'){
			return;
		}
		else{		
			coutxy( Head_Of_Topic_Line , Head_Of_Topic_Row + Topic_Blank*5 ,"                  ");
			continue;
		} 
	}

}
