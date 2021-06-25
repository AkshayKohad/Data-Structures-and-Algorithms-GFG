class Solution{
public:
    int maxBalls(int N, int M, int a[], int b[]){
        int sum1 = 0, sum2 = 0, ans = 0, i, j;
        for(i = 0,j = 0;i < N && j < M;){
    	  	if(a[i] < b[j]){
    	  		sum1 += a[i];
    	  		i++;
    		}
    		else if(a[i] > b[j]){
    	  		sum2 += b[j];
    	  		j++;
    		}
    		else{
    			sum1 += a[i];
    			while(i+1 < N && a[i+1] == b[j]){
    			    i++;
    			    sum1 += a[i];
    		    }
                sum2 += b[j];
    			while(j+1 < M && b[j+1] == a[i]){
    			    j++;
    			    sum2 += b[j];
    		    }
    			i++;
    			j++;
    			if(sum1 > sum2)
    			    ans += sum1;
    		    else
    		        ans += sum2;
		        sum1 = sum2 = 0;
    		}
        }
    	for(j;j < M;j++)
    	    sum2 += b[j];
        for(i;i < N;i++)
    	    sum1 += a[i];
        if(sum1 > sum2)
		    ans += sum1;
	    else
	        ans += sum2;
        return ans;
    }
};
