#include <iostream>
#include <vector>
using namespace std;

int func(int N){
    if(N==0){
        return 0;
    }
    return N+func(N-1);
}

int GCD(int m,int n){
    if(n==0){
        return m;
    }
    return GCD(n,m%n);
}

int Fibo(int n){
    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    return Fibo(n-1)+Fibo(n-2);
}

int main(void){
    int a=10;
    cout<<func(a)<<endl;
    cout<<GCD(1000,240)<<endl;
    cout<<Fibo(30)<<endl;
    return 0;
}