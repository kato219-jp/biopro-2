#include <iostream>
#include <vector>
using namespace std;

int main(void){
    string DNA_sequence;
    cin >> DNA_sequence;

    int start = DNA_sequence.find("ATG");

    if(start == string::npos){
        cout << "CDS was not found" << endl;
        return 0;
    }

    bool found = false;

    for(int i = start + 3; i <= DNA_sequence.size() - 3; i += 3){
        string codon = DNA_sequence.substr(i, 3);

        if(codon == "TAA" || codon == "TAG" || codon == "TGA"){
            found = true;
            break;
        }
    }
    if(found){
        cout<<"CDS was found"<<endl;
    }
    return 0;
}