
 unsigned long long int sqrtbs(long long int n){
   unsigned long long int s = 0;
   unsigned long long int e = n;
   unsigned long long int mid = s+(e-s)/2;
   unsigned long long int ans;
   while(s<=e){
       unsigned long long int square = mid*mid;
       if(square == n){
           return mid;
       }
       else if(square<n){
           ans = mid;
           s = mid+1;
       }
       else{
           e = mid-1;
       }
       mid = s+(e-s)/2;
   }
   return ans;
}

int sqrtN(long long int N){
   return sqrtbs(N);
}