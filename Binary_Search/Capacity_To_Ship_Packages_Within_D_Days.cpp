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
        cnt+=(cur>0);
        return cnt;
    }
    int shipWithinDays(vector<int>& w, int d) {
        int s=0,e=0;
        for(auto i:w)
        {
            s=max(s,i);
            e+=i;
        }
        e+=10;
        while(s+1<e)
        {
            int mid=(s+e)/2;
            if(check(w,mid)<=d)
            {
                e=mid;
            }
            else{
                s=mid;
            }
        }
        if(check(w,s)<=d)
        {
            e=s;
        }
        return e;
    }
