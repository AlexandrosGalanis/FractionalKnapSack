//Alexandros Galanis icsd14027
//greedy O(n^2) its the complexity of the sorting algorithm
#include <iostream>

using namespace std;


int knapsack(int lenght, float w[],float v[],float capacity);

int main(){
    int lenght = 5,i,j;
    float capacity =7;
    float w[lenght],v[lenght],r[lenght];

    for(i=0 ; i < lenght; i++){
        cout<<"give v,w:\n";
        cin>>v[i]>>w[i];
    }

    for(i = 0 ; i < lenght; i++){
        r[i]=(float)v[i]/w[i];//float
    }

    for(i = 0 ; i < lenght; i++){
        for(j = i ; j < lenght; j++){
            if(r[i]<r[j]){
                float temp=r[i];
                r[i]=r[j];
                r[j]=temp;

                temp=w[i];
                w[i]=w[j];
                w[j]=temp;

                temp=v[i];
                v[i]=v[j];
                v[j]=temp;
            }
        }
    }

    knapsack(lenght, w, v, capacity);
    return 0;
}


int knapsack(int lenght, float w[], float v[], float capacity){

    float x[lenght],currentCapacity=capacity,total_profit=0.0;
    int i;

    for(i = 0; i < lenght; i++){
        x[i]=0.0;
    }

    for(i = 0; i < lenght; i++){
        if(w[i] > currentCapacity){
            break;
        }else{
            x[i]=1.0;
            total_profit+= v[i];
            currentCapacity-= w[i];
        }
    }
    //cout<<currentCapacity<<" "<<w[i];

    if(i < lenght){
        x[i]= currentCapacity/w[i];
    }
    total_profit+= x[i] * v[i];

    /*for(i = 0; i < lenght; i++){
        cout<<x[i];
    }*/
    cout<<"\n"<<total_profit;
}
