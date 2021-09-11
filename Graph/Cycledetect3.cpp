#include <bits/stdc++.h>
using namespace std;

//cycle detection in undirected graph using BFS 

void addedge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool BFS(vector<int> adj[],int j,bool visited[]){
    vector<int> p(6,-1);
    queue<pair<int,int>> q;
    visited[j] = true;
    q.push({j,-1});
    while(!q.empty()){
        int e = q.front().first;
        int par = q.front().second;
        q.pop();
        for(auto a : adj[j]){
            if(visited[j] == false){
                visited[j] = true;
                q.push({a,j});
            }else if(par  != a){
                return true;
            }
        }


    }
    return false;

}


bool checkcycle(vector<int> adj[],int v){
    bool visited[v+1];
    for(int i=0;i<v;i++){
        visited[i] = false;
    }

     for(int j=0;j<v;j++){
        if(visited[j] == false){
            if(BFS(adj,j,visited) == true){
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
    bool ans = checkcycle(adj,v);
    if(ans == true){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }


    return 0;
}
