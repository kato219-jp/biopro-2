#include<iostream>
#include<vector>
#include<fstream>
#include<cmath>
#include <map>
using namespace std;
const string aminoacid="ACDEFGHIKLMNPQRSTVWY";

void LoadFile(string file_name,vector<string>&aminoacid_seq, vector<int>& localization){
    ifstream ifs(file_name);
    if(!ifs){
        cerr<<"Cannot open file:"<<file_name<<endl;
        exit(1);
    }
    int num;
    ifs >> num;
    aminoacid_seq.resize(num);
    localization.resize(num);

    for(int i=0;i<num;i++){
        ifs >> aminoacid_seq[i];
        ifs >> localization[i];
    }
    ifs.close();
}
vector<double>Prob(string aminoacid_seq){
    vector<double> prob(20,0.0);
    map<char,int> aminoacid_index;
    for(int i=0;i<20;i++){
        aminoacid_index[aminoacid[i]]=i;
    }
    for(int i=0;i<aminoacid_seq.size();i++){
        prob[aminoacid_index[aminoacid_seq[i]]]+=1.0/aminoacid_seq.size();
    }
    return prob;
}
double Distance(vector<double>prob1,vector<double>prob2){
    double distance=0.0;
    for(int i=0;i<20;i++){
        distance+=(prob1[i]-prob2[i])*(prob1[i]-prob2[i]);
    }
    return sqrt(distance);
}
int Predict(vector<double>test_prob,vector<vector<double>>&train_prob,vector<int>&localization){
    double min_distance=1000000;
    int min_index=0;

    for(int i =0;i<train_prob.size();i++){
        double distance=Distance(test_prob,train_prob[i]);
        if(distance<min_distance){
            min_distance=distance;
            min_index=i;
        }
    }
    return localization[min_index];
}

int main(void){
vector<string>train_seq;
vector<int>train_localization;
vector<string>test_seq;
vector<int>test_localization;
LoadFile("train_mitochondrion_cytoplasm_dataset.txt",train_seq,train_localization);
LoadFile("test_mitochondrion_cytoplasm_dataset.txt",test_seq,test_localization);
double TP=0,TN=0,FP=0,FN=0;

vector<vector<double>>train_prob;
for(int i =0;i< train_seq.size();i++){
        train_prob.push_back(Prob(train_seq[i]));
    }

for(int i =0;i<test_seq.size();i++){
        vector<double> test_prob = Prob(test_seq[i]);
        int prediction =Predict(test_prob,train_prob,train_localization);
        if(prediction==1&&test_localization[i]==1){
            TP++;
        }
        else if(prediction==0&&test_localization[i]==0){
            TN++;
        }
        else if(prediction==1&&test_localization[i]==0){
            FP++;
        }
        else if(prediction==0&&test_localization[i]==1){
            FN++;
        }
}
    
double BA=1/2*(TP/(TP+FN)+TN/(TN+FP));
    cout<<"Balanced Accuracy:"<<BA<<endl;
    return 0;
}