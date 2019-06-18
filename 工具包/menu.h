#ifndef MENU_H
#define MENU_H
#include"include.h"
int menu()
{ 
	startmode();
	mouse(1);
	int mode=1,mode_d=1;
	int c1,c2;
	do
	{
		mode_d=mode;
		c1=getch();
		if(c1==224)
		{
			c2=getch();
			switch(c2)
			{
             case 72:
				 //cout<<"¤W";
				 mode--;
				 break;
             case 80:
				 //cout<<"¤U";
				 mode++;
				 break;
             case 75:
				 //cout<<"¥ª";
				 break;
             case 77:
				// cout<<"¥k";
				 break;
			}
			
		}
		if(mode<1)
		{
			mode=4;
		}
		else if(mode>4)
		{
			mode=1;
		}
		mouse_d(mode_d);
		mouse(mode);
	}while(c1!=13);
    return mode; 
}
#endif