class Solution {
public:
    int maximizeSweetness(vector<int>& a, int k) {
        int s=INT_MAX,e=0;
        for(auto i:a)
        {
            s=min(s,i);
            e+=i;
        }
        e+=10;
        e/=(k+1);
        while(s+1<e)
        {
            int mid=(s+e)/2;
            // i want every one to have more or equal to mid
            int c=0,cs=0;
            for(auto i:a)
            {
                cs+=i;
                if(cs>=mid)
                {
                    c++;
                    cs=0;
                }
            }
            if(c>k)
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
