class Solution {
public:
    bool check(int sz,string t)
    {
        string cur="";
        for(int i=0;i<sz;i++)
        {
            cur+=t[i];
        }
        map<string,bool> cnt;
        cnt[cur]=1;
        for(int i=sz;i<t.size();i++)
        {
            cur=cur.substr(1,cur.size()-1)+t[i];
            if(cnt[cur])
            {
                return 1;
            }
            cnt[cur]=1;
        }
        return 0;
    }
    int longestRepeatingSubstring(string k) {
        int s=0,e=k.size();
        while(s+1<e)
        {
            int mid=(s+e)/2;
            if(check(mid,k))
            {
                s=mid;
            }
            else
            {
                e=mid;
            }
        }
        return s;
    }
};
