class Solution {
public:
    int minimumMountainRemovals(vector<int>& a) {
        int n=a.size();
        map<int,int> dp1,dp2;
        dp1[0]=1;
        for(int i=1;i<a.size();i++)
        {
            dp1[i]=1;
            for(int j=i-1;j>-1;j--)
            {
                if(a[i]>a[j])
                {
                    dp1[i]=max(dp1[i],dp1[j]+1);
                }
            }
        }
        dp2[a.size()-1]=1;
        for(int i=a.size()-2;i>-1;i--)
        {
            dp2[i]=1;
            for(int j=i+1;j<a.size();j++)
            {
                if(a[j]<a[i])
                {
                    dp2[i]=max(dp2[i],dp2[j]+1);
                }
            }
        }
        int ans=-1;
        for(int i=0;i<a.size();i++)
        {
            if(dp1[i]==1 or dp2[i]==1)
            {
                continue;
            }
            ans=max(ans,dp1[i]+dp2[i]-1);
        }
        return a.size()-ans;
    }
};
