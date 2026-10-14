#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
using namespace std;

int main(void){
    ifstream ist("human_protein_interaction.txt");
    string line;

    map<string,int> pronum={};

    while(getline(ist,line)){
        string s=line.substr(0,line.find(" "));
        string t=line.substr(line.find(" ")+1);
        pronum[s]++;
        pronum[t]++;
    }
    ist.close();
    string maxpro;
    int maxnum=0;
    for(map<string,int>::const_iterator it=pronum.begin();it!=pronum.end();it++){
        if(it->second>maxnum){
            maxnum=it->second;
            maxpro=it->first;
        }
    }
    cout<<"最も相互作用するタンパク質は"<<maxpro<<"で、数は"<<maxnum<<"です"<<endl;
    return 0;
}