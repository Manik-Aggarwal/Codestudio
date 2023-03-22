#include <bits/stdc++.h>

vector<int> findCommonElements(vector<vector<int>> &mat)
{
    unordered_map<int,int> m;
    vector<int> ans;
    int row = mat.size();
    int col = mat[0].size();

    for(int i=0; i<col; i++) m[mat[0][i]] = 1;

    for(int i=1; i<row; i++){
        for(int j=0; j<col; j++){
        if (m.find(mat[i][j])!=m.end() && m[mat[i][j]] == i) m[mat[i][j]]++;
        }
    }

    for(pair<int, int> p : m){
        if(p.second == row) ans.push_back(p.first);
    }

    return ans;
}
