#include <bits/stdc++.h>
using namespace std;

//for directed graph t.c. o(v+e)


void addedge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
}

bool DFSres(vector<int> adj[],int j, bool visited[], bool res[]){
    visited[j] = true;
    res[j] = true;

    for(int a : adj[j]){
        if(visited[a] == false && DFSres(adj,a,visited,res)){
            return true;
        }else if(res[a] == true){
            return true;
        }
    }
    res[j] = false;
    return false;
}



bool DFS(vector<int> adj[],int v){
    bool visited[v+1];
    bool res[v+1];
    for(int i=0;i<v;i++){
        visited[i] = false;
    }
    for(int j=0;j<v;j++){
        if(visited[j] == false){
            if(DFSres(adj,j,visited,res) == true){
                return true;
            }   
        }
       
    }
    return false;
}

int main(){
    int v = 6;
    vector<int> adj[v];
    addedge(adj,0,1);
    addedge(adj,2,1);
    addedge(adj,2,3);
    addedge(adj,3,4);
    addedge(adj,4,5);
    addedge(adj,5,3);
    bool ans = DFS(adj,v);
    if(ans == true){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }



    return 0;
}