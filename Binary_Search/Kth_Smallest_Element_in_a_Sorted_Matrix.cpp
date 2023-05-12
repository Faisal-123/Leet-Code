class Solution {
public:
    int kthSmallest(vector<vector<int>>& a, int k) { 
    	int s=a[0][0]-10;
    	int ans=INT_MAX;
    	int e=1+a[a.size()-1][a.size()-1];
    	while(s+1<e)
    	{
    		int mid=(s+e)/2;
    		int eq=0,le=0;
    		for(int i=0;i<a.size();i++)
    		{
    			auto l=lower_bound(begin(a[i]),end(a[i]),mid);
    			auto u=upper_bound(begin(a[i]),end(a[i]),mid);
    			eq+=(u-l);
    			if(a[i][0]>=mid)
    			{
    				continue;
    			}
    			le+=(l-begin(a[i]));
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
