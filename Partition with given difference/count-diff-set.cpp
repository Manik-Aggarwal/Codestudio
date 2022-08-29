int mod = (int)(1e9+7);

//////////////////////Memoization//////////////////////////
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
        
    return dp[ind][target] = (notTaken + taken) % mod;
}

int solve(vector<int>& arr, int target){
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    return f(n-1, target, arr, dp);
}

int countPartitions(int n, int d, vector<int> &arr) {    
    int totalsum=0;
    for(auto it : arr)
        totalsum +=it;
    if(totalsum-d < 0 || (totalsum-d) % 2 ) return false;

    return solve(arr, (totalsum-d) / 2);
}

////////////////////////Tabulation////////////////////////
int f(vector<int> &num, int tar){
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
        
            dp[ind][target]= (notTaken + taken)%mod;
        }
    }
    return dp[n-1][tar];
}

int countPartitions(int n, int d, vector<int>& arr){
    int totSum = 0;
    for(int i=0; i<n;i++) totSum += arr[i];
    if(totSum-d <0 || (totSum-d)%2 ) return 0;
    
    return f(arr,(totSum-d)/2);
}

/////////////////////Space Optimisation//////////////////////////
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
        
            cur[target] = (notTaken + taken)%mod;
        }
        prev = cur;
    }
    return prev[tar];
}

int countPartitions(int n, int d, vector<int>& arr){
    int totSum = 0;
    for(int i=0; i<n;i++) totSum += arr[i];    
    if(totSum-d <0 || (totSum-d)%2 ) return 0;
    return findWays(arr,(totSum-d)/2);
}
  