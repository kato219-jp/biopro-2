#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cmath>

#define NUM_TISSUES 68
#define NUM_GENES 19594

using namespace std;

void LoadExpressionFile(string file_name,vector<string>&tissue_name, vector<string>& gene_name,
vector<vector<double> >& expression_matrix){
    ifstream ifs(file_name);
    if(!ifs){
        cerr<<"Cannot open expression file:"<<file_name<<endl;
        exit(1);
    }
    string tmp;
    ifs >> tmp;

    for(int i=0;i<NUM_TISSUES;i++){
        ifs >> tissue_name[i];
    }
    for(int i=0;i<NUM_GENES;i++){
        ifs >> gene_name[i];
        for(int j=0;j<NUM_TISSUES;j++){
            ifs>> expression_matrix[i][j];
        }
    }
    ifs.close();
}

int main(void){
    vector<string> tissue_name(NUM_TISSUES,"");
    vector<string> gene_name(NUM_GENES,"");
    vector<vector<double> > expression_matrix(NUM_GENES, vector<double>(NUM_TISSUES, 0.0));
    LoadExpressionFile("gene_expression.txt",tissue_name, gene_name, expression_matrix);

    vector<double> average(NUM_GENES,0.0);
    vector<double> variance(NUM_GENES,0.0);
    for(int i=0;i<NUM_GENES;i++){
        double sum=0;
        double var_sum=0.0;
        for(int j=0;j<NUM_TISSUES;j++){
            sum+=expression_matrix[i][j];
            double diff=expression_matrix[i][j]-average[i];
            var_sum+=diff*diff;
        }
        average[i]=sum/NUM_TISSUES;
        variance[i]=var_sum/NUM_TISSUES;
    }

vector<bool>used(NUM_GENES,false);
for(int n=0;n<5;n++){
    double max=-1.0;
    int max_number=-1;
    for(int i=0;i<NUM_GENES;i++){
        if(!used[i] && average[i]>max){
            max=average[i];
            max_number=i;
        }
    }

    cout<<n+1<<"位："<<"遺伝子名："<<gene_name[max_number]<<endl;
    used[max_number]=true;
}
cout<<" "<<endl;

vector<double> score(NUM_GENES,0.0);
for(int i=0;i<NUM_GENES;i++){
    score[i] =average[i]/(sqrt(variance[i])+0.01);
}

for(int n=0;n<5;n++){
    double max=-1.0;
    int max_index=-1;
    for(int i=0;i<NUM_GENES;i++){
        if(!used[i] && score[i]>max){
            max=score[i];
            max_index=i;
        }
    }
    cout<<n+1<<"位：遺伝子名："<<gene_name[max_index]<<endl;
    cout<<"score："<<score[max_index]<<endl;
    used[max_index]=true;
}
cout<<" "<<endl;

vector<double> tau(NUM_GENES,0.0);
for(int i=0;i<NUM_GENES;i++){
    double xmax = 0.0;
    int max_index=0;
    for(int j=0; j<NUM_TISSUES; j++){
        if(expression_matrix[i][j]>xmax){
            xmax=expression_matrix[i][j];
            max_index=j;
        }
    }
    if(xmax==0.0){
        tau[i]=0.0;
        continue;
    }
    double sum=0.0;
    for(int j=0;j<NUM_TISSUES;j++){
        sum+=1.0-expression_matrix[i][j]/xmax;
    }
    tau[i]=sum/(NUM_TISSUES-1);
}

vector<int> tissue_count(NUM_TISSUES,0);
for(int i=0;i<NUM_GENES;i++){
    if(tau[i]>=0.85){
        double xmax=0.0;
        int max_index=0;
        for(int j=0;j<NUM_TISSUES;j++){
            if(expression_matrix[i][j]>xmax){
                xmax=expression_matrix[i][j];
                max_index=j;
            }
        }
        tissue_count[max_index]++;
    }
}

for(int i=0;i<NUM_TISSUES;i++){
    cout<<tissue_name[i]<<":"<<tissue_count[i]<<endl;
}

int max_count=0;
int max_tissue=0;
for(int i=0;i<NUM_TISSUES;i++){
    if(tissue_count[i]>max_count){
        max_count=tissue_count[i];
        max_tissue=i;
    }
}

cout << "組織特異的発現遺伝子が最も多い組織は"<<tissue_name[max_tissue]<<endl;
cout << "遺伝子数："<<max_count<<endl;

return 0;
}