#include <bits/stdc++.h>

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    unordered_map<int,list<int>> adj;
    
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].push_back(v);
    }
    
    //indegree
    vector<int> indegree(n+1);
    for(auto i : adj){
        for(auto j : i.second) indegree[j]++;
    }
    
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indegree[i] == 0) q.push(i);
    }
    
    int count = 0;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        count++;
        
        for(auto x : adj[front]){
            indegree[x]--;
            if(indegree[x] == 0) q.push(x);
        }
    }
    
    if(count == n) return false; //no cycle detected
    else return true;
}