#include <bits/stdc++.h>
void dfs(unordered_map<int, list<int>> &adjList,unordered_map<int, bool> &visited, vector<int> &temp, int node){
    temp.push_back(node);
    visited[node] = true;
    
    for(auto x : adjList[node]){
        if(!visited[x]) dfs(adjList,visited,temp,x);
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;
    
    for(int i=0; i<E; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    vector<vector<int>> ans;
    
    for(int i=0; i<V; i++){
        if(!visited[i]){
            vector<int> temp;
            dfs(adjList,visited,temp,i);
            ans.push_back(temp);
        }
    }
    
    return ans;
}