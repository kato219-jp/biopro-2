#include <iostream>
#include <vector>
using namespace std;

struct Protein{
    string name;
    int length;
    double molecular_weight;
};

void Showprotein(Protein p){
    cout<<"名前："<<p.name<<endl;
    cout<<"長さ："<<p.length<<endl;
    cout<<"分子量："<<p.molecular_weight<<endl;
    cout<<endl;
}

int main(void){
    vector<Protein> proteins(5);
    proteins[0].name="PAK";
    proteins[0].length=545;
    proteins[0].molecular_weight=62000;

    proteins[1].name="MAPK1";
    proteins[1].length=360;
    proteins[1].molecular_weight=41000;
    
    proteins[2].name="CDK9";
    proteins[2].length=372;
    proteins[2].molecular_weight=43000;
    
    proteins[3].name="AKT1";
    proteins[3].length=480;
    proteins[3].molecular_weight=56000;
    
    proteins[4].name="TP53";
    proteins[4].length=393;
    proteins[4].molecular_weight=44000;

    for(int i=0;i<proteins.size();i++){
        Showprotein(proteins[i]);
    }
    double Average_molecular_weight=0.0;
    for(int i=0;i<proteins.size();i++){
        Average_molecular_weight+=proteins[i].molecular_weight/proteins.size();
    }
    for(int i=0;i<proteins.size();i++){
        if(proteins[i].molecular_weight>=Average_molecular_weight){
            cout<<proteins[i].name<<endl;
        }
    }
    

    return 0;    
}