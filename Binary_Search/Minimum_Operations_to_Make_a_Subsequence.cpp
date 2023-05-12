int dp[100009];
class Solution {
public:
    int minOperations(vector<int>& a, vector<int>& b) {
        int n=a.size();
        int m=b.size();
        map<int,int> eti;
        for(int i=1;i<=n;i++)
        {
            dp[i]=INT_MAX;
            eti[a[i-1]]=i;
        }
        vector<int> c;
        for(auto i:b)
        {
            if(eti.find(i)!=eti.end())
            {
                c.push_back(eti[i]);
            }
        }
        dp[0]=0;
        for(auto i:c)
        {
            dp[lower_bound(dp,dp+n,i)-dp]=i;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(dp[i]!=INT_MAX)
            {
                ans=i;
            }
        }
        return n-ans;
    }
};
