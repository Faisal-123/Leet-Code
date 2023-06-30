class Solution {
public:
    map<int ,vector<vector<int>>> adj;
    map<int,bool> vis;
    int n;
    void dfs(int i,int p)
    {
        vis[i]=1;
        for(auto j:adj[i])
        {
            if(j[0]<=p and !vis[j[1]])
                dfs(j[1],p);
        }
    }
    bool check(int p)
    {
        vis.clear();
        dfs(1,p);
        return (vis.size()==n);
    }
    int earliestAcq(vector<vector<int>>& a, int xd) {
        n=xd;
        for(auto qw:a)
        {
            int w=qw[0],c=qw[1],d=qw[2];
            adj[c].push_back({w,d});
            adj[d].push_back({w,c});
        }
        if(check(0))
        {
            return 0;
        }
        int s=0,e=1e9+1;
        while(s+1<e)
        {
            int mid=(s+e)/2;
            if(check(mid))
            {
                e=mid;
            }
            else
            {
                s=mid;
            }
        }
        if(e==(1e9+1))
        {
        return -1;
        }
        return e;
    }
};
