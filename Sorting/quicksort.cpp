#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &v,int s,int e){

    int p = v[e];
    int i = s - 1;

    for(int j=s;j<e;j++){
        if(v[j] < p){
            i++;
            swap(v[i],v[j]);
        }
    }
    swap(v[i+1],v[e]);
    return i+1;
}

void quicksort(vector<int> &v,int s,int e){
    if(s>=e){
        return;
    }
    int p = partition(v,s,e);
    quicksort(v,s,p-1);
    quicksort(v,p+1,e);

}



int main(){
    vector<int> v{9,5,3,2,1,6};
    int s =0;
    int e =  v.size()-1;
    quicksort(v,s,e);
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
}