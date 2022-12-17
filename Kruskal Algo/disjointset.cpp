#include<bits/stdc++.h>

bool cmp(vector<int> &a, vector<int> &b){
    return a[2] < b[2]; //sort acc to weight, weight is in 3rd column of edges
}

void makeSet(vector<int> &parent, vector<int> &rank, int n){
    for(int i=0; i<n; i++) parent[i] = i;
}

int findParent(vector<int> &parent, int node){
    if(parent[node] == node) return node;
    else return parent[node] = findParent(parent,parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
    int parent1 = findParent(parent,u);
    int parent2 = findParent(parent,v);
    
    if(rank[parent1] < rank[parent2]) parent[parent1] = parent2;
    else if(rank[parent2] < rank[parent1]) parent[parent2] = parent1;
    else{
        parent[parent2] = parent1;
        rank[parent1]++;
    }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    sort(edges.begin(), edges.end(), cmp); //sort acc to cmp function, TC = mlogm
    vector<int> parent(n);
    vector<int> rank(n,0);
    makeSet(parent,rank,n);
    
    int minWeight = 0;
    for(int i=0; i<edges.size(); i++){
        int u = findParent(parent, edges[i][0]);//TC = const
        int v = findParent(parent, edges[i][1]);
        int w = edges[i][2];
        
        if(u != v){//if different parents
            minWeight += w;
            unionSet(u,v,parent,rank);//TC = const
        }
    }
    
    return minWeight;
}