#include <iostream>
#include <vector>
using namespace std;

int main(void){
    vector<int> tissue;
    tissue.resize(10);
    for(int i=0;i<tissue.size();i++){
        cin>>tissue[i];
    }

    int max_tissue=-1;
    for(int i=0;i<tissue.size();i++){
        if(max_tissue<tissue[i]){
            max_tissue=tissue[i];
        }
    }

    bool if_special_check=true;
    for(int i=0;i<tissue.size();i++){
        if(max_tissue!=tissue[i]){
            if(max_tissue/10<=tissue[i]){
                if_special_check=false;
                break;
            }
        }
    }
    if(max_tissue>=100 && if_special_check){
        cout<<"special tissue"<<endl;
    }
    else{
        cout<<"NOT special tissue"<<endl;
    }
return 0;
}