#include<iostream>
#include<string>
#include"../header/Converter.h"
using namespace std;

string hexSub16bit(string arg1,string arg2,bool flag[],bool carry){
	
	string resultant = "";
	int variable;
	int parity;
	int value1[4];
	int value2[4];
	int tempAnswer[4];
	Converter_h_to_D(arg1,value1);
	Converter_h_to_D(arg2,value2);
	for(int i=3;i>=0;i--){
		
		if(value1[i] < value2[i]){
			
			tempAnswer[i] = (16 + value1[i]) - value2[i];
			if(i!=0)
				--value1[i-1];
			else{
				if(carry)
					flag[0] = true;
			}
		}
		else
		
			tempAnswer[i] = value1[i] - value2[i];
	}
	variable = tempAnswer[0]*16*16*16 + tempAnswer[1]*16*16 + tempAnswer[2]*16 + tempAnswer[3];
	bitset<16> dataInBinary(variable);

	parity = dataInBinary.count();
	if(parity%2 == 0 && parity!=0)
		flag[2] = true;
	else
		flag[2] = false;

	flag[7] = dataInBinary[7];
	
	if(parity == 0){

		flag[6] = true;
	}
	else{

		flag[6] = false;
	}
	
	for(int i = 3;i>=0;--i){
		
		if(tempAnswer[i]>=0 && tempAnswer[i]<=9)
			resultant = char('0'+tempAnswer[i]) + resultant;
		else if(tempAnswer[i]>=10 && tempAnswer[i]<=15)
			resultant = (char)('A'+(tempAnswer[i] - 10)) + resultant;
		}
	
	return resultant;
}