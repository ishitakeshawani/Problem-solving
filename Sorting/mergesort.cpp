#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &v,int s,int e){
    int i=s;
    int m = (s+e)/2;
    int j = m+1;

    vector<int> temp;

    while(i<=m and j<=e){
        if(v[i] < v[j]){
            temp.push_back(v[i]);
            i++;
        }else{
            temp.push_back(v[j]);
            j++;
        }
    }

    while(i<=m){
        temp.push_back(v[i++]);
        
    }
    while (j<=e){
        temp.push_back(v[j++]);
       
    }
    int k=0;
    for(int i=s;i<=e;i++){
        v[i] = temp[k++];
    }
    
    return;

}

void mergesort(vector<int> &v,int s,int e){

    if(s>=e){
        return;
    }


    int m = (s+e)/2;
    mergesort(v,s,m);
    mergesort(v,m+1,e);
    return merge(v,s,e);
}


int main(){
    
    vector<int> v;
    v = {6,8,2,3,9,0};
    int s =0;
    int e = v.size()-1;
    mergesort(v,s,e);
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;

}