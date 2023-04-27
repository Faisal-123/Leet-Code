class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int i=0;
        int j=0;
        vector<int> c;
        while(i<a.size() and j<b.size())
        {
            if(a[i]>b[j])
            {
                c.push_back(b[j]);
                j++;
            }
            else
            {
                c.push_back(a[i]);
                i++;
            }
        }
        while(i<a.size())
        {
            c.push_back(a[i]);
            i++;
        }
        while(j<b.size())
        {
            c.push_back(b[j]);
            j++;
        }
        if(c.size()%2==0)
        {
            int x=c.size()/2;
            return double((c[x]+c[x-1])/2.0);
        }
        else
        {
            int x=c.size()/2;
            return double(c[x]);
        }
    }
};
