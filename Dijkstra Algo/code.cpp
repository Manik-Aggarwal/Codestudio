#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0; i<edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    
    vector<int> dist(vertices,INT_MAX);
    set<pair<int,int>> st;
    dist[source] = 0;
    st.insert(make_pair(0,source));
    
    while(!st.empty()){
        auto top = *(st.begin());
        st.erase(st.begin());
        
        int topDist = top.first;
        int topNode = top.second;
        
        for(auto x : adj[topNode]){
            if(topDist + x.second < dist[x.first]){
                //before setting dist check if record is there in set
                auto record = st.find(make_pair(dist[x.first], x.first));
                if(record != st.end()) st.erase(record);
                
                dist[x.first] = topDist + x.second;
                st.insert(make_pair(dist[x.first], x.first));
            }
        }
    }
    return dist;
}