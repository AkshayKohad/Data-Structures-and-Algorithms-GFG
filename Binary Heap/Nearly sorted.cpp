class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int n, int k){
        // Your code here
        vector<int>a;
        unordered_map<int,int>mp;
        if(n==k)
        {
            priority_queue<int,vector<int>,greater<int>>pq(arr,arr+k);
         
        }
        
        
        
        else{
        priority_queue<int,vector<int>,greater<int>>pq(arr,arr+k+1);
       
       for(int i=k+1;i<n;i++)
       {
           a.push_back(pq.top());
           pq.pop();
           pq.push(arr[i]);
       }
       
      
        }
      
      
       while(pq.size()!=0)
           {
           a.push_back(pq.top());
           pq.pop();
           }
       
      
        return a;
    }
};
