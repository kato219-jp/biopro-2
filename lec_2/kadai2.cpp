#include <iostream>
#include <string>
using namespace std;

int HammingDistance(string x,string y){
    int count=0;
    int X=x.size();
    int Y=y.size();
    if(X!=Y){
        count=-1;
        return count;
    }
    else{
        for(int i=0;i<X;i++){
            if(x[i]!=y[i]){
                count=count+1;
            }
        }
        return count;
    }
}

int main(void){
    string a = "AACCGT";
    string b = "AATCAT";
    string c = "AACCG";

    int dist1 = HammingDistance(a, b);
    if (dist1 != -1) {
        cout << "Hamming Distance: " << dist1 << endl;
    }else{
        cout << "The two strings have different lengths." << endl;
    }
    int dist2 = HammingDistance(a, c);
    if (dist2 != -1) {
        cout << "Hamming Distance: " << dist2 << endl;
    }else{
        cout << "The two strings have different lengths." << endl;
    }

    return 0;
}