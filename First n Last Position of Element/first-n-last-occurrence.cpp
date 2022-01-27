int firstOccur(vector<int>& arr, int n, int key){
    int l=0, h=n-1;
    int mid = l + (h-l)/2;
    int ans = -1;
    
    while(l<=h){
        if(arr[mid] == key){
            ans = mid;
            h = mid - 1;
        }
        else if(arr[mid] < key) l = mid + 1;
        else h = mid -1 ;
        
        mid = l + (h-l)/2;
    }
    return ans;
}

int lastOccur(vector<int>& arr, int n, int key){
    int l=0, h=n-1;
    int mid = l + (h-l)/2;
    int ans = -1;
    
    while(l<=h){
        if(arr[mid] == key){
            ans = mid;
            l = mid + 1;
        }
        else if(arr[mid] < key) l = mid + 1;
        else h = mid -1 ;
        
        mid = l + (h-l)/2;
    }
    return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int,int> p;
    p.first = firstOccur(arr,n,k);
    p.second = lastOccur(arr,n,k);
    
    return p;
}