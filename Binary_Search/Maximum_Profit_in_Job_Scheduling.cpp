bool sorter(vector<int>& a,vector<int>& b)
{
    if(a[0]>b[0])
    {
        return 1;
    }
    else if(a[0]==b[0] and a[1]>b[1])
    {
        return 1;
    }
    return 0;
}
class Solution {
public:
    int jobScheduling(vector<int>& k, vector<int>& b, vector<int>& c){
        int n=k.size();
        vector<vector<int>> a;
        for(int i=0;i<n;i++)
        {
            a.push_back({k[i],b[i],c[i]});
        }
        sort(begin(a),end(a),sorter);
        map<int,int> dp;
        for(int i=0;i<n;i++)
        {
            dp[a[i][0]]=max(dp[a[i][0]],a[i][2]);
        }
        dp[100000001]=0;
        for(int i=0;i<n;i++)
        {
            dp[a[i][0]]=max(dp[a[i][0]],(*dp.upper_bound(a[i][0])).second);
            auto x=*dp.lower_bound(a[i][1]);
            if(a[i][2]+x.second >= dp[a[i][0]])
            {
                dp[a[i][0]]=a[i][2]+x.second;
            }
        }
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            if(dp.find(a[i][0])!=dp.end())
            {
                ans=max(ans,dp[a[i][0]]);
            }
        }
        return ans;
    }
};
