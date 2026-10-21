#include<iostream>
#include<cmath>
using namespace std;

float formula_plus(float a,float b,float c){
    float x=(-b+sqrt(b*b-4*a*c))/2*a;
    return x;
}
float formula_minus(float a,float b,float c){
    float x=(-b-sqrt(b*b-4*a*c))/2*a;
    return x;
}

float gosaformula_plus(float a,float b,float c){
    float x=(4*a*c)/(2*a*(-b-sqrt(b*b-4*a*c)));
    return x;
}
float gosaformula_minus(float a,float b,float c){
    float x=(-b-sqrt(b*b-4*a*c))/2*a;
    return x;
}

float gosaformula_bminus_plus(float a,float b,float c){
    float x=(-b+sqrt(b*b-4*a*c))/2*a;
    return x;
}
float gosaformula_bminus_minus(float a,float b,float c){
    float x=(4*a*c)/(2*a*(-b+sqrt(b*b-4*a*c)));
    return x;
}

int main(void){
    float a=1,b=-10000,c=1;
    cout<<"解は"<<formula_plus(a,b,c)<<"と"<<formula_minus(a,b,c)<<endl;
    if(b>0){
        cout<<"誤差を減らした解は"<<gosaformula_plus(a,b,c)<<"と"<<gosaformula_minus(a,b,c)<<endl;
    }else{
        cout<<"誤差を減らした解は"<<gosaformula_bminus_plus(a,b,c)<<"と"<<gosaformula_bminus_minus(a,b,c)<<endl;
    }

    return 0;
}

