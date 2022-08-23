#include<bits/stdc++.h>

// Recursion //////////////////////////////////////////////////////////////////////
int solve(int i, vector<int> &heights){
    if(i == 0) return 0; 
    
    int left = solve(i-1,heights) + abs(heights[i] - heights[i-1]);
    int right = INT_MAX;
    if(i>1) right = solve(i-2,heights) + abs(heights[i] - heights[i-2]);
    
    return min(left,right);
}

int frogJump(int n, vector<int> &heights)
{
    return solve(n-1, heights);
}

// Memoization ///////////////////////////////////////////////////////////////////
int solve(int i, vector<int> &heights, vector<int> &dp){
    if(i == 0) return 0; 
    
    if(dp[i] != -1) return dp[i];
    
    int left = solve(i-1,heights, dp) + abs(heights[i] - heights[i-1]);
    int right = INT_MAX;
    if(i>1) right = solve(i-2,heights, dp) + abs(heights[i] - heights[i-2]);
    
    return dp[i] = min(left,right);
}

int frogJump(int n, vector<int> &heights)
{    
    vector<int> dp(n+1,-1);
    return solve(n-1, heights, dp);
}

//  Tabulation///////////////////////////////////////////////////////////////////
int frogJump(int n, vector<int> &heights)
{    
    vector<int> dp(n,0);
    dp[0] = 0;
    
    for(int i=1; i<n; i++){
        int first = dp[i-1] + abs(heights[i] - heights[i-1]);
        int second = INT_MAX;
        if(i>1) second = dp[i-2] + abs(heights[i] - heights[i-2]);
        
        dp[i] = min(first,second);
    }
    return dp[n-1];
}

// Space optimized ////////////////////////////////////////////////////////////////
int frogJump(int n, vector<int> &heights)
{    
    int prev = 0;
    int prev2 = 0;
    
    for(int i=1; i<n; i++){
        int first = prev + abs(heights[i] - heights[i-1]);
        int second = INT_MAX;
        if(i>1) second = prev2 + abs(heights[i] - heights[i-2]);
        
        int curr = min(first,second);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}