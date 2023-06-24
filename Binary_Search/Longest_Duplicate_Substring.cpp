#define ll long long
ll powmod(ll a,ll b,ll modulo)
{
    ll p=1;
    for(int i=1;i<=b;i++)
    {
        p=(p*a)%modulo;
    }
    return p;
}
class Solution {
public:
    string match(string &T,ll m,ll d=256,ll q=10000000000037)
    {
        ll cnt=0;
        ll n=T.size();
        ll h=powmod(d,m-1,q);
        ll t0=0;
        for(int i=0;i<m;i++)
        {
            t0=((d*t0)%q + T[i])%q;
        }
        set<ll> hav;
        for(int s=0;s<=(n-m);s++)
        {
            if(hav.find(t0)!=hav.end())
            {
                string ans="";
                for(int j=0;j<m;j++)
                {
                    ans+=T[s+j];
                }
                return ans;
            }
            else
            {
                hav.insert(t0);
            }
            t0=(((((t0-(T[s]*h))*256)%q)+q)%q);
            t0%=q;
            if(s < (n-m))
                t0+=T[s+m];
        }
        return "";
    }
    bool match(string& T,string& P)
    {
        ll cnt=0;
        for(int i=0;i<=((int)T.size()-(int)P.size());i++)
        {
            bool p=1;
            for(int j=0;p and j<(int)P.size();j++)
            {
                if(T[j+i]!=P[j])
                {
                    p=0;
                }
            }
            if(p)
            {
                cnt++;
            }
            if(cnt==2)
            {
                return 1;
            }
        }
        return 0;
    }
    string check(string k,ll mid)
    {
        for(int i=0;i<((ll)k.size()-mid);i++)
        {
            string gh=k.substr(i,mid);
            if(match(k,gh))
            {
                return gh;
            }
        }
        return "";
    }
    string longestDupSubstring(string k) {
        ll s=0,e=k.size();
        string pos="";
        while(s+1<e)
        {
            ll mid=(s+e)/2;
            string po=match(k,mid);
            if(po.size()>0)
            {
                s=mid;
                pos=po;
            }
            else
            {
                e=mid;
            }
        }
        return pos;
    }
};
