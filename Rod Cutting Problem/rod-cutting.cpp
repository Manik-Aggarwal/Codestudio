int f(vector<int>& cuts, int ind, int N, vector<vector<int>>& dp){
        if(ind == 0){
            return N*cuts[0];
        }
        if(dp[ind][N]!=-1) return dp[ind][N];

        int notTaken = 0 + f(cuts,ind-1,N,dp);

        int taken = INT_MIN;
        int rodLength = ind+1; // as indexing starts from 0 so rod length will be 1 foe 0th
        if(rodLength <= N) taken = cuts[ind] + f(cuts,ind,N-rodLength,dp);

        return dp[ind][N] = max(notTaken,taken);
    }

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(price, n-1, n, dp);
}

/////////////////////////Tabulation/////////////////////////////
int cutRod(vector<int>& price,int n) {

    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    
    for(int i=0; i<=n; i++){
        dp[0][i] = i*price[0];
    }
    
    for(int ind=1; ind<n; ind++){
        for(int length =0; length<=n; length++){
        
             int notTaken = 0 + dp[ind-1][length];
    
             int taken = INT_MIN;
             int rodLength = ind+1;
             if(rodLength <= length)
                taken = price[ind] + dp[ind][length-rodLength];
        
             dp[ind][length] = max(notTaken,taken);   
        }
    }
    
    return dp[n-1][n];
}

///////////////////////////Space Optimisation/////////////////////////////
int cutRod(vector<int>& price,int n) {

    vector<int> prev(n+1,0);
    vector<int> curr(n+1,0);
    
    for(int i=0; i<=n; i++){
        prev[i] = i*price[0];
    }
    
    for(int ind=1; ind<n; ind++){
        for(int length =0; length<=n; length++){
        
             int notTaken = 0 + prev[length];
    
             int taken = INT_MIN;
             int rodLength = ind+1;
             if(rodLength <= length)
                taken = price[ind] + curr[length-rodLength];
        
             curr[length] = max(notTaken,taken);   
        }
        prev = curr;
    }
    
    return prev[n];
}
