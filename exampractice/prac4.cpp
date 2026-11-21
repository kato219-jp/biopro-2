#include <iostream>
#include <vector>
using namespace std;

int main(void){
    string DNA;
    cin>>DNA;
    double count_C=0;
    double count_G=0;
    
    for(int i=0;i<DNA.size();i++){
        if(DNA[i]=='C'){
            count_C++;
        }
        else if(DNA[i]=='G'){
            count_G++;
        }
    }
    double GC_content=(count_C+count_G)/DNA.size()*100;
    cout<<GC_content<<endl;
    return 0;
}