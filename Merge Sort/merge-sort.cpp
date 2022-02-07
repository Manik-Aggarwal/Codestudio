void merge(vector<int> &arr, int s, int e){
    int mid = s + (e-s)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int k = s;
    for(int i=0; i<len1; i++) first[i] = arr[k++];
    k = mid+1;
    for(int i=0; i<len2; i++) second[i] = arr[k++];

    //merging
    int i=0, j=0;
    k = s;
    while(i<len1 && j<len2){
        if(first[i]<second[j]) arr[k++] = first[i++];
        else arr[k++] = second[j++];
    }
    for(; i<len1; i++) arr[k++] = first[i];
    for(; j<len2; j++) arr[k++] = second[j];
    
    delete [] first;
    delete [] second;
}

void solve(vector<int> &arr, int s, int e){
    //base case
    if(s>=e) return;

    int mid = s + (e-s)/2;
    //sort left part
    solve(arr, s, mid);
    //sort right part
    solve(arr, mid+1, e);
    //merge
    merge(arr, s, e);
}

void mergeSort(vector<int> &arr, int n) {
    solve(arr, 0, n-1);
}