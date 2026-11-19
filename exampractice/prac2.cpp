#include <iostream>
#include <vector>
using namespace std;

int main(void){
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        cout<<s[s.size()-1-i];
    }
    cout<<endl;
    return 0;
}