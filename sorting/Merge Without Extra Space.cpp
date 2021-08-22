

 // } Driver Code Ends


// Function to merge two input arrays
// arr1[], arr2[]: input arrays
// n, m: size of arr1[] and arr2[] respectively
void merge(int arr1[], int arr2[], int n, int m) 
{ 
    //Your code here
    //n is size of arr1
    //m is size of arr2
    
   int t;
    
    int j=0;
    int i=n-1;
    while(j<m && i>=0)
    {
        if(arr1[i]>arr2[j])
        {
            t=arr2[j];
            arr2[j]=arr1[i];
            arr1[i]=t;
            i--;
            j++;
        }
        
        else
        break;
    }
    
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
} 


// { Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    int arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    
	    merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            printf("%d ", arr1[i]); 
        
       
	    for (int i = 0; i < m; i++) 
		    printf("%d ", arr2[i]); 
	    
	    cout<<endl;
	}

	return 0; 
} 
  // } Driver Code Ends
