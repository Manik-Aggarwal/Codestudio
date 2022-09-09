#include<bits/stdc++.h>
#define ll long long
int mod=1e9+7;

long long mcm(int i, int j, int isTrue, string& exp, vector<vector<vector<int>>>&dp){
   if(i>j) return 0;
   if(i==j){
       if(isTrue) return exp[i]=='T';
       else return exp[i]=='F';
   }
   
   if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
   ll ways=0;
   for(int k=i+1;k<=j-1;k+=2){
       //calculate no. of true false for left and right partition
       ll lT= mcm(i,k-1,1, exp,dp);  //true of left  partition 
       ll lF= mcm(i,k-1,0, exp,dp);  // false of left part.
       ll rT= mcm(k+1,j,1, exp,dp);
       ll rF= mcm(k+1,j,0, exp,dp);
       
       if(exp[k]=='&'){
           if(isTrue) ways= (ways+ (lT *rT)%mod)%mod;  //to get true in &
           else ways= (ways+ (lF*rT)%mod + (lT*rF)%mod + (lF*rF)%mod)%mod;  //to get false
       }
       else if(exp[k]=='|'){
           if(isTrue) ways=(ways+ (lT *rT)%mod+ (lF*rT)%mod + (lT*rF)%mod)%mod;  //to get true in |
           else ways= (ways+ (lF*rF)%mod)%mod;  //to get false
       }
       else if(exp[k]=='^'){
           if(isTrue) ways= (ways+ (lF*rT)%mod + (lT*rF)%mod)%mod;  //to get true in ^
           else ways= (ways+ (lT*rT)%mod + (lF*rF)%mod)%mod;  //to get false
       }
   }
   return dp[i][j][isTrue]= ways;
}
int evaluateExp(string & exp) {
   int n=exp.size();
   vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(n+1, vector<int>(3,-1)));
   return mcm(0,n-1,1,exp,dp);
}
