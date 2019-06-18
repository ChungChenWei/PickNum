#ifndef MAP_H
#define MAP_H
#include"include.h"
#define mapx 177
#define mapy 51
using namespace std;
void frame()
{
	gotoxy(0,0);
	char map[mapy][mapx];
	for(int i=0;i<mapy;i++)
	{
		for(int j=0;j<mapx;j++)
		{
			if(i==0||i==(mapy-1))
			{
				map[i][j]='#';
			}
			else if(j==0||j==(mapx-1))
			{
				map[i][j]='#';
			}
			else
			{
				map[i][j]=' ';	
			}		
		}
	}
	for(int i=0;i<mapy;i++)
	{
		for(int j=0;j<mapx;j++)
		{
	
			cout<<map[i][j];
		}
	}
}
#endif