long long mergeInversion(long long * arr, int left, int right){
    long long mid= (left+right)/2;

    long long k=0;
    long long i=left;
    long long j=mid+1;
    long long inv_count=0;

    //left, mid;  mid+1, right;
    long long temp[right-left+1];
    
    while(i<=mid && j<=right){
        if(arr[i] <= arr[j]){
            temp[k++]=arr[i++];
        } else{
            temp[k++]=arr[j++];
            inv_count+= (mid-i+1); // (left ka end- current left ind+1 ) => total element jo humne chora
        }
    }

    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=right){
        temp[k++]=arr[j++];
    }

    for(long long i=left;i<=right;i++){
        arr[i]=temp[i-left];
    }
    return inv_count;
}

long long countInversion(long long* arr, int left, int right){
    if(left>=right) return 0;

    long long mid= (left+right)/2;

    //dividing step
    long long a=countInversion(arr, left, mid);
    long long b=countInversion(arr, mid+1, right);
    //merging step
    long long c=mergeInversion(arr, left, right);

    return a+b+c;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    return countInversion(arr, 0, n-1);
}