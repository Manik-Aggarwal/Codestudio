#include <bits/stdc++.h>

bool isCyclicBFS(int src, unordered_map<int,bool> &visited,unordered_map<int, list<int>> &adj){
    unordered_map<int,int> parent;
    parent[src] = -1;
    visited[src] = true;
    queue<int> q;
    q.push(src);
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        for(auto x : adj[front]){
            if(visited[x] == true && x != parent[front]) return true;
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
                parent[x] = front;
            }
        }
    }
    
    return false;
}

////////////////////////////////////////
bool isCyclicDFS(int node, int parent, unordered_map<int,bool> &visited,unordered_map<int, list<int>> &adj){
    visited[node] = true;
    
    for(auto x: adj[node]){
        if(!visited[x]){
            bool cycle = isCyclicDFS(x,node,visited,adj);
            if(cycle) return true;
        }
        else if(x != parent) return true;
    }
    
    return false;
}
////////////////////////////////////////

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{    
    // adjacency list
    unordered_map<int, list<int>> adj;
    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    //to handle disconnected components
    unordered_map<int,bool> visited;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            // bool ans = isCyclicBFS(i,visited,adj);
            bool ans = isCyclicDFS(i,-1,visited,adj);
            if(ans == 1) return "Yes";
        }
    }
    return "No";
}