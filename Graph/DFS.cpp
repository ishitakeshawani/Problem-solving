#include <bits/stdc++.h>
using namespace std;

void addedge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFS(vector<int> adj[],int s,bool visited[]){
    visited[s] = true;
    cout<<s<<" ";
    for(int a : adj[s]){
        if(visited[a] == false){
            DFS(adj,a,visited);
        }
    }
}



int main(){
    int v = 5;
    vector<int> adj[v];
    addedge(adj,0,1);
    addedge(adj,0,2);
    addedge(adj,1,2);
    addedge(adj,1,3);
    addedge(adj,2,4);
    addedge(adj,2,3);
    addedge(adj,3,4);
    bool visited[v+1];
    for(int i=0;i<v;i++){
        visited[i] = false;
    }
    for(int j=0;j<v;j++){
        if(visited[j] == false){
            DFS(adj,j,visited);
        }
    }



    return 0;
}