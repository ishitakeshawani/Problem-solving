#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> &v,int s,int e){
    int i=s;
    int m = (s+e)/2;
    int j = m+1;
    int cnt=0;
    vector<int> temp;

    while(i<=m and j<=e){
        if(v[i] < v[j]){
            temp.push_back(v[i]);
            i++;
        }else{
            cnt += (m-i+1);
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
    
    return cnt;

}

int mergesort(vector<int> &v,int s,int e){

    if(s>=e){
        return 0;
    }


    int m = (s+e)/2;
    int c1 = mergesort(v,s,m);
    int c2 = mergesort(v,m+1,e);
    int ci = merge(v,s,e);
    return c1+c2+ci;
}


int main(){
    
    vector<int> v;
    v = {6,8,2,3,9,0};
    int s =0;
    int e = v.size()-1;
    int c = mergesort(v,s,e);
    
    cout<<c;
   
    cout<<endl;
    return 0;

}