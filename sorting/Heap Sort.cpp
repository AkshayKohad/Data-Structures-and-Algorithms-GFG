void heapify(int arr[], int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    
    if(left<n && arr[left]>arr[largest])
    largest=left;
    
    if(right<n && arr[right]>arr[largest])
    largest = right;
    
    if(largest!=i)
    {
        swap(&arr[largest],&arr[i]);
        heapify(arr,n,largest);
    }
}

// Main function to do heap sort
void buildHeap(int arr[], int n) {
    // Build max heap
    for(int i=(n-2)/2;i>=0;i--)
    {
        heapify(arr,n,i);
    }
    
    while(n!=1)
    {
        swap(&arr[0],&arr[n-1]);
        n--;
        heapify(arr,n,0);
    }
    
}
