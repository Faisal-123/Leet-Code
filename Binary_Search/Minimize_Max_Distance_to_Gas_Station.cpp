class Solution {
public:
bool check(vector<int>& a,int p,double k)
{
    for (int i=1;i<a.size();i++)
    {
        if (a[i]-a[i-1]>k)
        {
            p-=int((a[i]-a[i-1])/k);
        }
    }
    return (p>=0);
}
    double minmaxGasDist(vector<int> a, int k) {
        double s=0,e=1e9+10,eps=1e-7;
        sort(begin(a),end(a));
        while (s+eps<e)
        {
            double mid=(s+e)/2;
            if (check(a,k,mid))
                e=mid;
            else
                s=mid;           
        }
        return s;
    }
};
