class Solution {
public:
    int maxValue(vector<vector<int>>& e, int k) {
        int n=e.size();
        auto comp = [] (vector<int>& a,vector<int>& b) -> bool {return a[1]<b[1];};
        sort(begin(e),end(e),comp);
        map<int,int> dp1={{0,0}};
        for(int i=0;i<k;i++)
        {
            map<int,int> dp2={{0,0}};
            for(int j=0;j<n;j++)
            {
                int cur=prev(dp1.lower_bound(e[j][0]))->second;
                if(cur+e[j][2] > dp2.rbegin()->second)
                {
                    dp2[e[j][1]]=cur+e[j][2];
                }
            }
            swap(dp1,dp2);
        }
        return dp1.rbegin()->second;
    }
};
