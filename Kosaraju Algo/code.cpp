#include<bits/stdc++.h>
void dfs(int node,unordered_map<int,bool>&visited,stack<int>&s, unordered_map<int,list<int>> &adjlist)
{
      visited[node]=true;
    for(auto nbr:adjlist[node])
    {
        if(!visited[nbr])
        {
            dfs(nbr,visited,s,adjlist);
        }
    }
    //topological logic
    s.push(node);    
}

void transdfs(int node,unordered_map<int,bool>&visited,unordered_map<int, list<int>> &adjlist)
{
    visited[node]=true;
     for(auto nbr:adjlist[node])
    {
        if(!visited[nbr])
        {
            transdfs(nbr,visited,adjlist);
        }
    }  
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
      // adj list
  unordered_map<int, list<int>> adjlist;
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i][0];
    int v = edges[i][1];

    adjlist[u].push_back(v);
  }
   //step 1: sort all node  
    //topological sort
    stack<int>s;
    unordered_map<int,bool>visited;
    for(int i=0;i<v;i++)
    {     
        if(!visited[i])
        {
            dfs(i,visited,s,adjlist);
        }
    }
    
    //step 2:
    //create transpose
    unordered_map<int,list<int>>transpose;
    for(int i=0;i<v;i++){
          visited[i]=0;
    for(auto nbr:adjlist[i])
    {
        transpose[nbr].push_back(i);
    }
    }
    //step 3:
      //call dfs using above ordering (transpose ordering)
    int count=0;
   while(!s.empty())
   {
       int top=s.top();
       s.pop();
       if(!visited[top])
       {
            count++;
           transdfs(top,visited,transpose);  
       }
   }
    return count;    
}