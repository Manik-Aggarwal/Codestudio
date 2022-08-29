// int f(int ind, int sum, vector<int> &nums){
//     if(ind == 0){
//         if(sum == 0 || sum == nums[0]) return 1;
//         if(sum == 0 && nums[0] == 0) return 2;
//         return 0;
//     }
//     if(ind == 0) return nums[0] == sum;
    
//     int include = 0;
//     if(nums[ind] <= sum) include = f(ind-1, sum-nums[ind], nums);
    
//     int exclude = f(ind-1, sum, nums);
    
//     return include + exclude;
// }

// int findWays(vector<int> &num, int tar)
// {
//     return f(num.size()-1, tar, num);
// }

// int f(int ind, int sum, vector<int> &nums, vector<vector<int>> &dp){
//     if(ind == 0){
//         if(sum == 0 || sum == nums[0]) return 1;
//         if(sum == 0 && nums[0] == 0) return 2;
//         return 0;
//     }
//     if(dp[ind][sum] != -1) return dp[ind][sum];
    
//     int include = 0;
//     if(nums[ind] <= sum) include = f(ind-1, sum-nums[ind], nums, dp);
    
//     int exclude = f(ind-1, sum, nums, dp);
    
//     return dp[ind][sum] = include + exclude;
// }

// int findWays(vector<int> &num, int tar)
// {
//     int n = num.size();
//     vector<vector<int>> dp(n, vector<int>(tar+1, -1));
//     return f(n-1, tar, num, dp);
// }

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar+1, 0));
    
    for(int i=0; i<n; i++) dp[i][0] = 1;
    if(num[0]<=tar) dp[0][num[0]] = 1;
    
    for(int ind = 1; ind<n; ind++){
        for(int sum= 1; sum<=tar; sum++){    
            int include = 0;
            if(num[ind]<=sum) include = dp[ind-1][sum-num[ind]];
            
            int exclude = dp[ind-1][sum];
        
            dp[ind][sum]= exclude + include;
        }
    }
    
    return dp[n-1][tar];
}

// int findWays(vector<int> &num, int tar)
// {
//     int n = num.size();
//     vector<int> prev(tar+1,0);
//     vector<int> curr(tar+1,0);
    
//     prev[0] = curr[0] = 1;
//     if(num[0]<=tar) prev[num[0]] = 1;
    
//     for(int ind = 1; ind<n; ind++){
//         for(int sum= 1; sum<=tar; sum++){
//             int include = 0;
//             if(num[ind]<=sum) include = prev[sum-num[ind]];
            
//             int exclude = prev[sum];
        
//             curr[sum]= exclude + include;
//         }
//         prev = curr;
//     }
    
//     return prev[tar];
// }

//working only memoized