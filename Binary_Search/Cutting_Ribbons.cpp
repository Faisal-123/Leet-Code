int  check(int b,vector<int> a)
{
    int an=0;
    for(auto i:a)
    {
        an+=(i/b);
    }
    return an;

}
int maxLength(vector<int>&ribbons,int k)
{
    int s=0,e=1e5+12;
    while (s+1<e)
    {
        int mid=(s+e)>>1;
        if (check(mid,ribbons)>=k)
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
