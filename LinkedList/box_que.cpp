#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,t;
    cin>>n>>t;
    vector<int> v;
    for(int i=0;i<n;i++){
        int e;
        cin>>e;
        v.push_back(e);
    }
    int low = 0, high = v.size()-1;

       
        while (low <= high) {
            int mid = low + (high-low)/2;

            if (v[mid] < t)
                low = mid+1;
            else
                high = mid-1;
        }

        cout<<low;
        return 0;

}