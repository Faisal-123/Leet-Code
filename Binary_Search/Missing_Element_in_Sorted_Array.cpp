int missingElement(vector<int>& a, int k) {
    int ans=INT_MAX;
    for(int i=0;i<a.size()-1;i++)
    {
        if(a[i]+k<a[i+1])
        {
            ans=a[i]+k;
            break;
        }
        else{
            k-=(a[i+1]-a[i]-1);
        }
    }
    if(ans==INT_MAX)
    {
        ans=a[a.size()-1]+k;
    }
    return ans;
}
