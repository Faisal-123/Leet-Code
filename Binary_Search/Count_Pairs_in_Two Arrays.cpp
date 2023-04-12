class Solution {
public:
    long long countPairs(vector<int>& a, vector<int>& b) {
        vector<int> c;
        long long ans=0;
        for(int i=0;i<a.size();i++)
        {
            c.push_back(a[i]-b[i]);
        }
        sort(begin(c),end(c));
        for(int i=0;i<c.size();i++)
        {
            int x=c[i];
            int s=i+1;
            int e=c.size();
            while(s+1<e)
            {
                int mid=(s+e)/2;
                if(x<=(-1*c[mid]))
                {
                    s=mid;
                }
                else
                {
                    e=mid;
                }
            }
            if(s<c.size() and (c[s]*-1)>=x)
            {
                s++;
            }
            ans+=max(((int)c.size()-s),0);
        }
        return ans;
    }
};
