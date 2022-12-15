#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int,list<int>> adj;
    
    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
    }
    
    //indegree
    vector<int> indegree(v);
    for(auto i : adj){
        for(auto j : i.second) indegree[j]++;
    }
    
    queue<int> q;
    for(int i=0; i<v; i++){
        if(indegree[i] == 0) q.push(i);
    }
    
    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        ans.push_back(front);
        for(auto x : adj[front]){
            indegree[x]--;
            if(indegree[x] == 0) q.push(x);
        }
    }
    
    return ans;
}