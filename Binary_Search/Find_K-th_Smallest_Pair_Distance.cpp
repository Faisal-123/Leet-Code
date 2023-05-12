class Solution {
public:
    bool check(int x,vector<int>& b,int k,int& ans)
    {
        // cout<<"FOR "<<x<<' ';
        int eq=0;
        int le=0;
        for(int i=0;i<b.size();i++)
        {
            auto l=lower_bound(begin(b),end(b),b[i]-x);
            auto u=upper_bound(begin(b),end(b),b[i]-x);
            eq+=(u-l);
            le+=(begin(b)+i-u);
        }
        // cout<<eq<<' '<<le<<endl;
        if(le<k)
        {
            if((le+eq)>=k)
            {
                ans=min(ans,x);
            }
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int smallestDistancePair(vector<int>& a, int k) {
        sort(begin(a),end(a));
        int ans=INT_MAX;
        int s=-1,e=a[a.size()-1]-a[0]+10;
        while(s+1<e)
        {
            int mid=(s+e)/2;
            if(check(mid,a,k,ans))
            {
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
