#include<iostream>
#include<cmath>
using namespace std;

double f1(double x){
        return exp(x)+x-5;
}

double f2(double x){
    return cbrt(x);
}

void Answer_1(double a,double b){
    double c=b-a;
    int count=0;
    while(c>1e-12){
        if(f1((a+b)/2)>0){
            b=(a+b)/2;
        }
        if(f1((a+b)/2)<0){
            a=(a+b)/2;
        }
        c=b-a;
        count++;
        }
    cout<<"試行回数は"<<count<<"回"<<endl;
    cout<<"解の範囲は"<<a<<"<x<"<<b<<endl;
}

void Answer_2(double a,double b){
    double c=b-a;
    int count=0;
    while(c>1e-12){
        if(f2((a+b)/2)>0){
            b=(a+b)/2;
        }
        if(f2((a+b)/2)<0){
            a=(a+b)/2;
        }
        c=b-a;
        count++;
        }
    cout<<"試行回数は"<<count<<"回"<<endl;
    cout<<"解の範囲は"<<a<<"<x<"<<b<<endl;
}

int main(void){
    double a=0,b=2;
    Answer_1(a,b);
    double c=-0.1,d=0.2;
    Answer_2(c,d);
    return 0;
}