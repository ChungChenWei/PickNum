#include "../Header/WordGenerator.h"

#include "../Header/ConsoleInterface.h"
#include "../Header/DataSet.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int Num_Fac;
int Num_X;
int Num_Y;
static char s[30];
static int gx,gy;
static string WordRoute="./Number/originalX3/0.txt";//file處理，都是以主程式為相對路徑起點 
void Word_Informatio(){
	fstream fint;
	WordRoute[WordRoute.size()-5]='0';
//	WordRoute[WordRoute.size()-7]='3';		//WordSize;
	fint.open(WordRoute.c_str(),ios::in);	
	fint >> Num_Y >> Num_X >> Num_Fac;
	fint.close();
}
void WordGenerator(int num){
	fstream fint;
	WordRoute[WordRoute.size()-5]=num+'0';	//+48 = '0';
//	WordRoute[WordRoute.size()-7]='3';		//WordSize;
	//cout << WordRoute;
	fint.open(WordRoute.c_str(),ios::in);	
	fint >> Num_Y >> Num_X >> Num_Fac;
	//Num_Fac = 1;
	
	fint.get();
	for(int i = 0 ; i < Num_Y ; i++){
		fint.getline(s,30);
		for(int r = 0 ; r < Num_Fac ; r++){
			for(int j = 0 ; j < Num_X ; j++){
				for(int k = 0 ; k < Num_Fac ; k++){
					if(s[j]=='1')	printf("■",s[j]);
					else			printf("  ",s[j]);
				}
			}
			getxy(gx,gy);
			gotoxy(gx - 2 * Num_Fac * Num_X , gy+1);
			//getch();
		}
	}
	cout << endl;
	fint.close();
}

