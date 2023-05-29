#include<iostream>
#include<string>
#include"../header/addrfun.h"
#include"../header/Converter.h"
using namespace std;


string JNC(string data1,string pc,string registers[],bool flag[]){
    if(flag[0]==false){
        return data1;
    }else{
        string res="";

        int value[4];
        int returnvalue[]={0,0,0,3};
        int carry=0;
        
        Converter_h_to_D(pc,value);

        for(int i=3;i>=0;i--){
            int resvalue = value[i]+returnvalue[i]+carry;
            carry=resvalue/16;
            resvalue%=16;

            if(resvalue>=0 && resvalue<=9){
                res=(char)('0'+resvalue)+res;
            }else{
                res=(char)('A'+(resvalue-10))+res;
            }
        }
        if(validAddr(res)){
            return res;
        }else{
            cout<<"Error In JNC Instruction"<<endl;
            exit(0);
        }

    }
}