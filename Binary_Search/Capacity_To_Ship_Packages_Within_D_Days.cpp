    int check(vector<int>& w,int m)
    {
        int cur=0,cnt=0;
        for(auto i:w)
        {
            if(cur+i>m)
            {
                cnt++;
                cur=0;
            }
            cur+=i;
        }
        cnt++;
        return cnt;
    }
    int shipWithinDays(vector<int>& w, int d) {
        int s=0,e=0;
        for(auto i:w)
        {
            e+=i;
        }
        e+=10;
        while(s+1<e)
        {

        }
    }
