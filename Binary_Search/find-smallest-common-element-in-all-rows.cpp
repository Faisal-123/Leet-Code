class Solution {
public:
    bool check(vector<int>& ro,int g)
    {
        int s=0,e=ro.size();
        while(s+1<e)
        {
            int mid=(s+e)/2;
            if(ro[mid]==g)
            {
                return 1;
            }
            if(ro[mid]<g)
            {
                s=mid;
            }
            else
            {
                e=mid;
            }
        }
        if(ro[(s+e)/2]==g)
        {
            return 1;
        }
        return 0;
    }
    int smallestCommonElement(vector<vector<int>>& mat) {
        for(int i=0;i<mat[0].size();i++)
        {
            for(int j=0;j<mat.size();j++)
            {
                int x=mat[j][i];
                bool p=1;
                for(int k=0;k<mat.size() and p;k++)
                {
                    p&=check(mat[k],x);
                }
                if(p)
                {
                    return x;
                }
            }
        }
        return -1;
    }
};
