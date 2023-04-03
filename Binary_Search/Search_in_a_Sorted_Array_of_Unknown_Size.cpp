int search(const ArrayReader& a, int b) {
    int s=-1,e=(int)1e4+3;
    long long ia=(1LL<<31)-1;
    int inf=ia;
    while(s+1<e)
    {
        int mid=(s+e)/2,ax=a.get(mid);
        if(ax==inf)
        {
            e=mid;
        }
        else if(ax>b)
        {
            e=mid;
        }
        else if(ax<b){
            s=mid;
        }
        else{
            return mid;
        }
    }
    return -1;
}
