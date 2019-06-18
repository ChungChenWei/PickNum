#ifndef COUT_XY_H
#define COUT_XY_H
#include"include.h"
using namespace std;
void cout_xy(int x,int y,char* s)
{
	gotoxy(x,y);
	cout<<s;
}
#endif