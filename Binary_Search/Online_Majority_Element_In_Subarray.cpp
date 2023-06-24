class MajorityChecker {
public:
    map<int,vector<int>> ind;
    vector<int> b;
    MajorityChecker(vector<int>& arr) {
        srand(time(0));
        for(int i=0;i<arr.size();i++)
        {
            ind[arr[i]].push_back(i);
        }
        b=arr;
    }
    int query(int l, int r, int t) {
        // map<int,bool> fo;
        for(int i=0;i<20;i++)
        {
            int id=rand()%(r-l+1);
            id+=l;
            int a=b[id];
            int s=0,e=ind[a].size();
            while(s+1<e)
            {
                int mid=(s+e)/2;
                if(ind[a][mid]<=r)
                {
                    s=mid;;
                }
                else
                {
                    e=mid;
                }
            }
            if(ind[a][s]>r)
            {
                return -1;
            }
            int ls=s;
            int rs=lower_bound(begin(ind[a]),end(ind[a]),l)-begin(ind[a]);
            int cnt=ls-rs+1;
            if(cnt>=t)
            {
                return a;
            }
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
