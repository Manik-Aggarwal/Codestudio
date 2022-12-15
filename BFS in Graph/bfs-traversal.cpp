#include <bits/stdc++.h> 
void prepareAdjList(unordered_map<int, set<int>> &adjList,vector<pair<int, int>> &edges){
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void solve(unordered_map<int, set<int>> &adjList, unordered_map<int,bool> &visited, vector<int>&ans, int node){
    queue<int> q;
    q.push(node);
    visited[node] = true;
    
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);
        
        for(auto x : adjList[frontNode]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
            }
        }
    }
    
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adjList;
    unordered_map<int,bool> visited;
    vector<int> ans;
    
    prepareAdjList(adjList,edges);
    
    for(int i=0; i<vertex; i++){
        if(!visited[i]) solve(adjList,visited,ans,i);
    }
    
    return ans;
}