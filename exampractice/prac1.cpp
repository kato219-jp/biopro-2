#include <iostream>
#include <vector>
using namespace std;

int main(void){
    string line;
    cin>>line;
   string result;
   int count=0;
   for(int i=0;i<line.size()-1;i++){
    if(i==line.size()-2){
    if(line[i]==line[i+1]){
        count=count+2;
        result+=line[i]+to_string(count);
    }
    else if(line[i]!=line[i+1]){
        result+=line[i]+to_string(count);
        result+=line[i+1]+to_string(1);
    }
    }else{
        if(line[i]==line[i+1]){
            count++;
        }
        else if(line[i]!=line[i+1]){
            count++;
            result+=line[i]+to_string(count);
            count=0;
        }
    }
    }
   for(int i=0;i<result.size();i++){
    cout<<result[i];
   }
   cout<<endl;
return 0;
}