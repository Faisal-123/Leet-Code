class Solution {
public:
    int maximumScore(vector<int>& a, int k) {
        int n=a.size();
        int pre1[n+1];
        int pre2[n+1];
        memset(pre1,0,sizeof(pre1));
        memset(pre2,0,sizeof(pre2));
        pre1[0]=pre2[0]=INT_MAX;
        for(int i=1,j=k;j>-1;i++,j--)
        {
            pre1[i]=min(pre1[i-1],a[j]);
        }
        for(int i=1,j=k;j<n;i++,j++)
        {
            pre2[i]=min(pre2[i-1],a[j]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int x=a[i];
            int l=0,r=n+1;
            while(l+1<r)
            {
                int mid=(l+r)/2;
                if(pre1[mid]>=x)
                {
                    l=mid;
                }
                else
                {
                    r=mid;
                }
            }
            int j=l;
            l=0,r=n+1;
            while(l+1<r)
            {
                int mid=(l+r)/2;
                if(pre2[mid]>=x)
                {
                    l=mid;
                }
                else
                {
                    r=mid;
                }
            }
            if(j>0 and l>0)
            {
                ans=max(ans,min(pre2[l],pre1[j])*(int)(l+j-1));
            }
        }
        return ans;
    }
};
