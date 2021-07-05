#include <iostream>
using namespace std;

int main(){
    int r=2,c=3;
    int a[c][r];
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; i < r; j++)
        {
            a[i][j]=i+j;
        }
        
    }
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    
}