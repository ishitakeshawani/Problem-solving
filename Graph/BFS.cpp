#include <bits/stdc++.h>
using namespace std;

void addedge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void BFS(vector<int> adj[],int v,int s){
    bool visited[v+1];
    for (int i = 0; i < v; i++)
    {
       visited[i] = false;
    }
    queue<int> q;
    visited[s] = true;
    q.push(s);

    while (!q.empty())
    {
        int e = q.front();
        q.pop(); 
        cout<<e<<" ";
        for(int j:adj[e]){
            if(visited[j] == false){
                visited[j] = true;
                q.push(j);
            }
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
    BFS(adj,v,0);
    return 0;
}