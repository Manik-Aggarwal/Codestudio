///////////////////////////Memoization////////////////////////
int f(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
    if(ind == 0){
        if(target==0 && arr[0]==0) return 2;
        if(target==0 || target == arr[0]) return 1;
        return 0;
    }
    
    if(dp[ind][target]!=-1) return dp[ind][target];
        
    int notTaken = f(ind-1,target,arr,dp);
    
    int taken = 0;
    if(arr[ind]<=target) taken = f(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target] = notTaken + taken;
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,-1));
    return f(n-1, tar, num, dp);
}

///////////////////////Tabulation///////////////////////////
int findWays(vector<int> &num, int tar){
     int n = num.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,0));
    if(num[0] == 0) dp[0][0] = 2;  // 2 cases -pick and not pick
    else dp[0][0] = 1;  // 1 case - not pick 
    if(num[0]!=0 && num[0]<=tar) dp[0][num[0]] = 1;
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 0; target<=tar; target++){
            int notTaken = dp[ind-1][target];
    
            int taken = 0;
            if(num[ind]<=target) taken = dp[ind-1][target-num[ind]];
        
            dp[ind][target]= notTaken + taken;
        }
    }
    return dp[n-1][tar];
}

///////////////////////////Space Optmization///////////////////////
int findWays(vector<int> &num, int tar){
     int n = num.size();
    vector<int> prev(tar+1,0);
    if(num[0] == 0) prev[0] = 2;  // 2 cases -pick and not pick
    else prev[0] = 1;  // 1 case - not pick
    
    if(num[0]!=0 && num[0]<=tar) prev[num[0]] = 1;
    
    for(int ind = 1; ind<n; ind++){
        vector<int> cur(tar+1,0);
        for(int target= 0; target<=tar; target++){
            int notTaken = prev[target];
            int taken = 0;
            if(num[ind]<=target) taken = prev[target-num[ind]];
        
            cur[target] = notTaken + taken;
        }
        prev = cur;
    }
    return prev[tar];
}