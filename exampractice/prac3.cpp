#include <iostream>
#include <vector>
using namespace std;

int main(void){
    string s;
    cin>>s;
    int max_count=-1;
    int count=1;
    for(int i=1;i<s.size();i++){
        if(s[i]==s[i-1]){
            count++;
            if(max_count<count){
                max_count=count;
            }
        }
        else if(s[i]!=s[i-1]){
            if(max_count<count){
                max_count=count;
            }
            count=1;
        }
    }
cout<<max_count<<endl;
return 0;
}