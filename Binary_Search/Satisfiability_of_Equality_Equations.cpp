class Solution {
public:
    map<char,char> par;
    char get(char a)
    {
        if(par[a]==a)
        {
            return a;
        }
        return par[a]=get(par[a]);
    }
    void join(char a,char b)
    {
        a=get(a);
        b=get(b);
        par[b]=a;
    }
    bool equationsPossible(vector<string>& p) {
        bool ans=1;
        for(char a='a';a<='z';a++)
            par[a]=a;
        for(auto j:p)
        {
            if(j[1]=='!')
            {
                j[0]=get(j[0]);
                j[3]=get(j[3]);
                if(j[0]==j[3])
                {
                    ans=0;
                    break;
                }
            }
            else
            {
                if(j[0]==j[3])
                {
                    continue;
                }
                join(j[0],j[3]);
            }
        }
        for(auto j:p)
        {
            if(j[1]=='!')
            {
                j[0]=get(j[0]);
                j[3]=get(j[3]);
                if(j[0]==j[3])
                {
                    ans=0;
                    break;
                }
            }
            else
            {
                if(j[0]==j[3])
                {
                    continue;
                }
                join(j[0],j[3]);
            }
        }
        return ans;
    }
};
