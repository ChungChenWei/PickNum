#ifndef STARTMODE_H
#define STARTMODE_H
#include"include.h"
using namespace std;
void startmode()
{
	system("mode 177");
	frame();
	gotoxy(0,0);
	int a=79,b=9;
	cout_xy(a,b,  "�}    �l    �C    ��");
	cout_xy(a,2*b,"Ū    ��    �O    ��");
	cout_xy(a,3*b,"��       ��       �]");
	cout_xy(a,4*b,"��    �}    �C    ��");
}
#endif