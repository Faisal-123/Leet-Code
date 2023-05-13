class SummaryRanges {
public:
    set<int> a;
    SummaryRanges() {   
    }
    void addNum(int x) {
        a.insert(x);
    }
    vector<vector<int>> getIntervals() {
        int l,r;
        l=r=-1;
        vector<vector<int>> ans;;
        for(auto i:a)
        {
            if(l==-1)
            {
                l=r=i;
            }
            else
            {
                if(i==r+1)
                {
                    r=i;
                }
                else
                {
                    ans.push_back({l,r});
                    l=r=i;
                }
            }
        }
        if(l!=-1)
            ans.push_back({l,r});
        return ans;     
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
