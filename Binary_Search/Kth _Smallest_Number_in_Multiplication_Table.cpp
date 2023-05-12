class Solution {
public:
    int findKthNumber(int n, int m, int k) {
     	long long s=0;
    	long long ans=n*m + 10;
    	long long e=1+n*m;
    	while(s+1<e)
    	{
    		long long mid=(s+e)/2;
    		int eq=0,le=0;
    		for(int i=1;i<=n;i++)
    		{
    			eq+=(mid%i==0 and mid/i <= m);
    			le+=min((mid/i)-(mid%i==0 and mid/i <= m),(long long)m);
    		}
    		if(le<k)
    		{
    			if((le+eq)>=k)
    			{
    				ans=min(ans,mid);
    			}
    			s=mid;
    		}
    		else
    		{
    			e=mid;
    		}
    	}
        return ans;       
    }
};
