#include<iostream>
#include<string>
#include"../header/addrfun.h"
using namespace std;

string JMP(string data1,string registers[],bool flag[]){
    if(validAddr(data1)){
        return data1;
    }else{
        cout<<"Error In JMP instruction"<<endl;
        exit(0);
    }
}