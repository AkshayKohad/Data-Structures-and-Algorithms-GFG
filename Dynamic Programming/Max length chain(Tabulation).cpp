/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
bool mycmp(struct val a,struct val b)
{
    return a.first<b.first;
}
int maxChainLen(struct val p[],int n)
{
//Your code here
sort(p,p+n,mycmp);
int i, j, max = 0;
int mcl[n];

for ( i = 0; i < n; i++ )
        mcl[i] = 1;
     
    /* Compute optimized chain
    length values in bottom up manner */
    for ( i = 1; i < n; i++ )
        for ( j = 0; j < i; j++ )
            if ( p[i].first > p[j].second &&
                    mcl[i] < mcl[j] + 1)
                mcl[i] = mcl[j] + 1;
     
    // mcl[i] now stores the maximum
    // chain length ending with Pair i
     
    /* Pick maximum of all MCL values */
    for ( i = 0; i < n; i++ )
        if ( max < mcl[i] )
            max = mcl[i];
     
    /* Free memory to avoid memory leak */
     
    return max;
}
