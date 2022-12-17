#include<bits/stdc++.h>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	unordered_map<int,list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        for(auto x : adj[front]){
            if(!visited[x]){
                visited[x] = true;
                q.push(x);
                parent[x] = front;
            }
        }
    }
    
    vector<int> ans;
    int node = t;
    ans.push_back(node);
    
    while(node != s){
        node = parent[node];
        ans.push_back(node);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
