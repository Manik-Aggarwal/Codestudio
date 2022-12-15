#include <bits/stdc++.h>

bool isCyclic(int node, unordered_map<int,bool> &visited, unordered_map<int,bool> &dfsvisited,unordered_map<int, list<int>> &adj){
    visited[node] = true;
    dfsvisited[node] = true;
    
    for(auto x : adj[node]){
        if(!visited[x]){
            bool temp = isCyclic(x,visited,dfsvisited,adj);
            if(temp) return true;
        }
        else if(dfsvisited[x] == true) return true;
    }
    
    dfsvisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    unordered_map<int,list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].push_back(v);
    }
    
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsvisited;
    
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            bool cycle = isCyclic(i,visited,dfsvisited,adj);
            if(cycle) return true;
        }
    }
    
    return false;
}