int binarySearch(int *input, int n, int val)
{	int s = 0;
    int mid = s + (n-s)/2;

    while(s<=n){
        if(input[mid] == val) return mid;
        else if(input[mid] > val) n = mid-1;
        else s = mid+1;
        mid = s + (n-s)/2;
    }
    return -1;
}