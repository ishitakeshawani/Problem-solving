#include <iostream>
using namespace std;

int main(){
    int m=3,n=2;
    int **a;
    a = new int*[m];
    for(int i=0;i<m;i++){
        a[i] = new int[n];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = i*j;
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}