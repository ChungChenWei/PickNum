#include<iostream>

int ScreenWide=10;
int ScreenDeep=10;

int main(){
	for(int i = 0 ; i <= ScreenDeep ; i++){
		for(int j = 0 ; j <= ScreenWide ; j++)
			if(!i || !j || i == ScreenDeep || j == ScreenWide )	
				std::cout << "#";
			else
				std::cout << " ";
		std::cout << std::endl;
	}
	
}
