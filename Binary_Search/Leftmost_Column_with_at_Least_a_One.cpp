int leftMostColumnWithOne(BinaryMatrix &a) {
    vector<int> als=a.dimensions();
    int n=als[0],m=als[1],ans=INT_MAX;
    for(int i=0;i<n;i++)
    {
        int s=0,e=m;
        while(s+1<e)
        {
            int mid=(s+e)/2;
            if(a.get(i,mid)==1)
            {
                e=mid;
            }
            else{
                s=mid;
            }
        }
        if(a.get(i,s)==1)
        {
            e=s;
        }
        if(e!=m)
            ans=min(ans,e);
    }
    if(ans==INT_MAX)
    {
        ans=-1;
    }
    return ans;
}
