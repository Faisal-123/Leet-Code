#define int1 long long
class Solution {
public:
    int minWastedSpace(vector<int>& a, vector<vector<int>>& b) {
        sort(begin(a),end(a));
        int1 ans=LLONG_MAX;
        int1 pre[a.size()+2];
        pre[0]=0;
        for(int i=0;i<a.size();i++)
        {
            pre[i+1]=pre[i]+a[i];
        }
        for(auto ka:b)
        {
            sort(begin(ka),end(ka));
            if(a[a.size()-1]>ka[ka.size()-1])
            {
                continue;
            }
            int1 cur=0;
            int1 e=-1;
            int1 i=0;
            while(e!=(a.size()-1) and i<ka.size())
            {
                int1 u=upper_bound(begin(a),end(a),ka[i])-begin(a)-1;
                if(u>-1)
                {
                    cur+=(ka[i]*(u-e))-(pre[u+1]-pre[e+1]);
                    e=u;
                }
                i+=1;
            }
            if(e==(a.size()-1))
            {
                ans=min(ans,cur);
            }
        }   
        if(ans==LLONG_MAX)
        {
            ans=-1;
        }
        ans%=((int1)pow(10,9)+7);
        return ans;
    }
};
