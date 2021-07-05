#include <iostream>
#include <vector>
using namespace std;

int main(){
    int m=3,n=2;
    vector<vector<int>> v;
    for(int i=0;i<m;i++){
        vector<int> vi;
        for(int j=0;j<n;j++){
            vi.push_back(i+j);
        }
        v.push_back(vi);
    }

     for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}