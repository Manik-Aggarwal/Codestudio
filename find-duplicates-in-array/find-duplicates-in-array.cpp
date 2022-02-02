int findDuplicate(vector<int> &arr, int n){
   int count[n] = {0};
   int ans=0;
   for(int i=0;i<n;i++) count[arr[i]]++;
   
   for(int i=0;i<n;i++){
       if(count[i]>1){
           ans=i;
           break;
       }
   }
     return ans;  
}