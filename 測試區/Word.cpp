#include "ConsoleInterface.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int Num_Fac;
int Num_X;
int Num_Y;
static char s[100];
static int x,y;
static string tests="../Number/originalX3/0.txt";//file處理，都是以主程式為相對路徑起點
static string testo="../Number/original2115/0.txt";//file處理，都是以主程式為相對路徑起點  

int main(){
	for(int num=0;num<10;num++){
	fstream fint,fout;
	tests[tests.size()-5]=num+48;	//+48 = '0';
	testo[testo.size()-5]=num+48;	//+48 = '0';
	//cout << testo;
	fint.open(tests.c_str(),ios::in);
	//fout.open(testo.c_str(),ios::out);
	
	fint >> Num_Y >> Num_X >> Num_Fac;
	Num_Fac = 1;
	cout << Num_Y*Num_Fac << " " << Num_X*Num_Fac << " " << Num_Fac <<endl;
	fout << Num_Y*Num_Fac << " " << Num_X*Num_Fac << " " << 1 <<endl;
	
	fint.get();
	for(int i = 0 ; i < Num_Y ; i++){
		fint.getline(s,100);
		for(int r = 0 ; r < Num_Fac ; r++){
			for(int j = 0 ; j < Num_X ; j++){
				for(int k = 0 ; k < Num_Fac ; k++){
					if(s[j]=='1')	cout << "■", fout << 1;
					else			cout << "  ", fout << 0;
				}
			}
			cout << endl;
			fout << endl;
		}
	}
	cout << endl;
	fout << endl;
	system("pause");
	}
	return 0;
}

