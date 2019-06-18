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
	cout_xy(a,b,  "開    始    遊    戲");
	cout_xy(a,2*b,"讀    取    記    錄");
	cout_xy(a,3*b,"排       行       榜");
	cout_xy(a,4*b,"離    開    遊    戲");
}
#endif