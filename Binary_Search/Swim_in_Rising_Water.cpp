// #define int int
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
class Solution {
public:
    int get(int c,int v)
    {
        return ((c+1)*50)+v+1;
    }
    int swimInWater(vector<vector<int>>& a) {
        // ((i+1)*50)+(j+1)
        cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false); 
        if(a.size()==1)
        {
            return 0;
        }
        queue<tuple<int,int>> b;
        int vis[100000];
        memset(vis,0,sizeof(vis));
        int x=0,y=0;
        vis[get(x,y)]=max(1,max(0,a[0][0]));
        b.push({x,y});
        while(b.size())
        {
            tie(x,y)=b.front();
            if(y+1<a.size() and (!vis[get(x,y+1)] or vis[get(x,y+1)]>max(vis[get(x,y)],a[x][y+1])))
            {
                vis[get(x,y+1)]=max(vis[get(x,y)],a[x][y+1]);
                b.push({x,y+1});
            }
            if(y-1>-1 and (!vis[get(x,y-1)] or vis[get(x,y-1)]>max(vis[get(x,y)],a[x][y-1])))
            {
                vis[get(x,y-1)]=max(vis[get(x,y)],a[x][y-1]);
                b.push({x,y-1});
            }
            if(x-1>-1 and (!vis[get(x-1,y)] or vis[get(x-1,y)]>max(vis[get(x,y)],a[x-1][y])))
            {
                vis[get(x-1,y)]=max(vis[get(x,y)],a[x-1][y]);
                b.push({x-1,y});
            }
            if(x+1<a.size() and (!vis[get(x+1,y)] or vis[get(x+1,y)]>max(vis[get(x,y)],a[x+1][y])))
            {
                vis[get(x+1,y)]=max(vis[get(x,y)],a[x+1][y]);
                b.push({x+1,y});
            }
            b.pop();
        }
        return vis[get(a.size()-1,a.size()-1)];
    }
};
