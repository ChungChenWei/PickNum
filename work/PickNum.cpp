#include"../Header/PickNum.h"
#include"../Header/DataSet.h"
#include<time.h>
#include<stdlib.h>

int Num_Min, Num_Max;	//©‚≈“Ωd≥Ú 

void srandSet(){
	unsigned seed = (unsigned)time(NULL);
	srand(seed);
}
void PickNum(int &o){
	o = rand() % Num_Max  + Num_Min;
}
