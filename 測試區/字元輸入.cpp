#include<string>
#include<iostream>
using namespace std;
int main(){
	string s;
	char c[50];
	getline(cin,s);
	cout << s << endl;
	cin.getline(c,50);
	cout << c << endl;
	
	return 0;
}
