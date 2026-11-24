#include <iostream>
#include <string>
using namespace std;

int main(void){
    string s1="asdfghj";
    string s2="asdvbnb";
   int hamming=0;
    for(int i=0;i<s1.size();i++){
        if(s1[i]==s2[i]){
            hamming++;
        }
    }
    cout<<hamming<<endl;
    return 0;
}
