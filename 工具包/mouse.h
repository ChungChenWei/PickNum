#ifndef MOUSE_H
#define MOUSE_H
#include"include.h"
using namespace std;
void mouse(int b)
{
	int a=79,c=9;
	gotoxy(a-5,b*c);
	cout<<">";
	gotoxy(a+25,b*c);
	cout<<"<";
	gotoxy(a+10,b*c);
}
void mouse_d(int b)
{
	int a=79,c=9;
	gotoxy(a-5,b*c);
	cout<<" ";
	gotoxy(a+25,b*c);
	cout<<" ";
	gotoxy(a+10,b*c);
}
#endif