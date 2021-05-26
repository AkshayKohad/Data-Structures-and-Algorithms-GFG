// using STL first
class Solution
{
    public:
    //Function to return kth largest element from an array.
    int KthLargest(int arr[], int n, int k) {
        // Your code here
        priority_queue<int>pq(arr,arr+n);
        
        int i=0;
        int res;
        while(i!=k)
        {
            res=pq.top();
            i++;
            pq.pop();
        }
        return res;
    }
};
