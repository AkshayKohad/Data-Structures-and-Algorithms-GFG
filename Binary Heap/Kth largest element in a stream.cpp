// APPROACH -> 1


class Solution
{
    public:
    //Function to print kth largest element for each element in the stream.
    void kthLargest(int arr[], int n, int k)
    {
    	// your code here
    	priority_queue<int,vector<int>,greater<int>>pq(arr,arr+k);
    	int i=0;
    
    	
    	
    	while(i<k-1)
    	{
    	     cout<<"-1 ";
    	     i++;
    	}
    	
    	i=k;
    	for(;i<n;)
    	{
    	     
    	  cout<<pq.top()<<" ";
    	  pq.push(arr[i]);
    	  i++;
    	  pq.pop();
    	  
    	    
    	}
    	cout<<pq.top();
    	//if(pq.size()!=0)
    
    }
};






//APPROACH -> 2

class Solution
{
    public:
    //Function to print kth largest element for each element in the stream.
    void kthLargest(int arr[], int N, int k)
    {
        //implementing MinHeap using priority queue.
    	priority_queue<int,vector<int>,greater<int>> pq; 
    	
    	for(int i=0;i<N;i++)
    	{
    	    //if size of priority queue is less than k, we push 
    	    //arr[i] in priority queue.
    	    if(pq.size() < k) 
    			pq.push(arr[i]);
    		else 
    		{
    		    //if top element of priority queue is smaller than arr[i], 
    		    //we pop the front element and push arr[i] in priority queue.
    			if(arr[i] > pq.top()) 
    			{
    				pq.pop();
    				pq.push(arr[i]);
    			}
    		}
    		
    		//if size of priority queue is less than k, we print -1.
    		if(pq.size()<k)
    			cout<<-1<<" ";
    		//else we print the top element of the priority queue.
    		else
    			cout<<pq.top()<<" "; 
    	}
    }
};
