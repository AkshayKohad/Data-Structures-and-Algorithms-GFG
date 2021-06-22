#include <stdio.h>

struct order{
    int a[60];
    int size;
};
int main() {
	//code
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n;
	    scanf("%d",&n);
	    int a[n];
	    for(int i=0;i<n;i++)
	    scanf("%d",&a[i]);
   struct order o[61];
	for(int i=0;i<61;i++)
	{
	    o[i].size=-1;
	}
	int hash[61];
	for(int i=0;i<=60;i++)
	{
	    hash[i]=0;
	}
	
	for(int i=0;i<n;i++)
	{
	  hash[a[i]]++;    
	}
	
	for(int i=0;i<=60;i++)
	{
	    if(hash[i]!=0)
	    {
	        o[hash[i]].size++;
	        o[hash[i]].a[o[hash[i]].size]=i;
	    }
	}
	int b[61];
	int j=0;
	for(int i=60;i>=0;i--)
	{
	    if(o[i].size!=-1)
	    {
	        for(int k=0;k<=o[i].size;k++)
	        {
	            b[j]=o[i].a[k];
	            j++;
	        }
	    }
	}
	
	for(int i=0;i<j;i++)
	{
	   int count=0;
	   while(count!=hash[b[i]])
	   {
	       printf("%d ",b[i]);
	       count++;
	       
	   }
	}
	printf("\n");
	}
	
	return 0;
}
