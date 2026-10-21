#include<iostream>
#include<cmath>
using namespace std;

double f1(double x){
        return exp(x)+x-5;
}
double f2(double x){
    return cbrt(x);
}
double differentiation_f1(double x){
    return exp(x)+1;
}
double differentiation_f2(double x){
    return 1/(3*cbrt(x)*cbrt(x));
}

void Answer_1(double a){
    int count=0;
    double b=a-f1(a)/differentiation_f1(a);
    while (b-a>1e-12||a-b>1e-12){
        a=b;
        b=a-f1(a)/differentiation_f1(a);
        count++;
    }
    cout<<"試行回数は"<<count<<"回"<<endl;
    if(a>b){
        cout<<"解の範囲は"<<b<<"<x<"<<a<<endl;
    }else{
        cout<<"解の範囲は"<<a<<"<x<"<<b<<endl;
    }
}
void Answer_2(double a){
    int count=0;
    double b=a-f2(a)/differentiation_f2(a);
    while(b-a>1e-12||a-b>1e-12){
        a=b;
        b=a-f2(a)/differentiation_f2(a);
        count++;
    }
    cout<<"試行回数は"<<count<<"回"<<endl;
    if(a>b){
        cout<<"解の範囲は"<<b<<"<x<"<<a<<endl;
    }else{
        cout<<"解の範囲は"<<a<<"<x<"<<b<<endl;
    }
}

int main(void){
double a=0;
Answer_1(a);
double b=-0.1;
Answer_2(b);
return 0;

}