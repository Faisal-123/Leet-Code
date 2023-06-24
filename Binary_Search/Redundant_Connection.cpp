class Solution {
public:
    int par[2008];
    int get(int x)
    {
        if(par[x]!=x)
        {
            par[x]=get(par[x]);

        }
        return par[x];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& v) {
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            par[i]=i;
        }
        bool p=(v.size()==(n-1));
        for(auto qw:v)
        {
            int a=qw[0];
            int b=qw[1];
            int a0=get(a);
            int b0=get(b);
            if(a0==b0)
            {
                return {a,b};
            }
            else
            {
                par[a0]=b0;
            }
        }
        return {0,0};
    }
};
