#include <bits/stdc++.h>
using namespace std;

//cycle detection in undirected graph using DFS

void addedge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool DFSres(vector<int> adj[],int i,bool visited[],int p){
    visited[i] = true;
    for(int a : adj[i]){
        if(visited[a] == false){
            if(DFSres(adj,a,visited,i) == true){
                return true;
            }
        }else if(a != p){
                return true;
            }            
        }
        return false;
    }



bool DFS(vector<int> adj[],int v){
    bool visited[v+1];
    for(int i=0;i<v;i++){
        visited[i] = false;
    }
    for(int j=0;j<v;j++){
        if(visited[j] == false){
            if(DFSres(adj,j,visited,-1) == true){
                return true;
            }   
        }
       
    }
    return false;
}



int main(){
    int v = 5;
    vector<int> adj[v];
    addedge(adj,0,1);
    addedge(adj,1,2);
    addedge(adj,2,3);
    addedge(adj,3,4);
    // addedge(adj,2,4);
    // addedge(adj,2,3);
    // addedge(adj,3,4);
    bool ans = DFS(adj,v);
    if(ans == true){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }

    return 0;
}