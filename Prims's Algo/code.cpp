#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int> > > adj;
    for(int i = 0; i < g.size(); i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    
    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parents(n+1);
    
    for(int i = 0; i <= n; i++){
        key[i] = INT_MAX;
        mst[i] = false;
        parents[i] = -1;
    }
    
    key[1] = 0;
    parents[1] = -1;
    
    for(int i = 1; i <= n; i++){
        int mini = INT_MAX;
        int u;
        
        //to find min of key vector
      for(int j = 1; j <=n; j++){
          if(mst[j] == false && key[j] < mini){
              u = j; 
              mini = key[j];
          }
      }
        mst[u] = true;
        
        for(auto it:adj[u]){
            int v = it.first;
            int w = it.second;
            if(mst[v] == false && w < key[v]){
                parents[v] = u;
                key[v] = w;
            }
        }  
    }
   vector<pair<pair<int, int>, int>> result;
    for(int i = 2; i <= n; i++){
        result.push_back({{parents[i], i}, key[i]});
    }
        return result;
    }
