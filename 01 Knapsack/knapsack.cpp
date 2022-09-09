int f(int ind, vector<int>&wt, vector<int>&val, int maxw){
    if(ind == 0){
        if(wt[0] <= maxw) return val[0];
        else return 0;
    }
    int notTake = 0 + f(ind-1, wt, val, maxw);
    int take = INT_MIN;
    if(wt[ind] <= maxw) take = val[ind] + f(ind-1, wt, val, maxw-wt[ind]);
    
    return max(take,notTake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    int ind = n-1;
    return f(ind,weight,value,maxWeight);
}

////////////////////////Memoization////////////////////////////
int f(int ind, vector<int>&wt, vector<int>&val, int maxw, vector<vector<int>> &dp){
    if(ind == 0){
        if(wt[0] <= maxw) return val[0];
        else return 0;
    }
    if(dp[ind][maxw] != -1) return dp[ind][maxw];
    
    int notTake = 0 + f(ind-1, wt, val, maxw, dp);
    int take = INT_MIN;
    if(wt[ind] <= maxw) take = val[ind] + f(ind-1, wt, val, maxw-wt[ind], dp);
    
    return dp[ind][maxw] = max(take,notTake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    int ind = n-1;
    vector<vector<int>> dp(n, vector<int>(maxWeight+1,-1));
    return f(ind,weight,value,maxWeight,dp);
}

///////////////////////////////Tabulation/////////////////////////
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
   vector<vector<int>> dp(n, vector<int>(maxWeight+1,0));
    for(int W = weight[0]; W<=maxWeight; W++) dp[0][W] = value[0];
    
    for(int ind=1; ind<n; ind++){
        for(int W=0; W<=maxWeight; W++){
            int notTake = 0 + dp[ind-1][W];
            int take = INT_MIN;
            if(weight[ind] <= W) take = value[ind] + dp[ind-1][W-weight[ind]];
            
            dp[ind][W] = max(take,notTake);
        }
    }
    
    return dp[n-1][maxWeight];
}

///////////////////////////////Space Optimisation/////////////////////////
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<int> prev(maxWeight+1,0);
    vector<int> curr(maxWeight+1,0);
    for(int W = weight[0]; W<=maxWeight; W++) prev[W] = value[0];
    
    for(int ind=1; ind<n; ind++){
        for(int W=0; W<=maxWeight; W++){
            int notTake = 0 + prev[W];
            int take = INT_MIN;
            if(weight[ind] <= W) take = value[ind] + prev[W-weight[ind]];
            
            curr[W] = max(take,notTake);
        }
        prev = curr;
    }
    
    return prev[maxWeight];
}

