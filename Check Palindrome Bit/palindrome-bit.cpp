bool checkPalindrome(long long N)
{
    long long rev = 0;
    long long k = N;
    
    while (k){
        //adding last digit in rev
        rev = (rev << 1) | (k & 1);
        //dropping off last digit of k
        k = k >> 1;
    }
    return N == rev;
}