class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& qw) {
        vector<int> co[4];
        for(int i=0;i<colors.size();i++)
        {
            co[colors[i]].push_back(i);
        }
        vector<int> hg;
        int q,w;
        for(auto as:qw)
        {
            q=as[0];
            w=as[1];
            // cout<<" have ";
            // for(auto i:co[w])
            // {
            //     cout<<i<<' ';
            // }
            // cout<<endl;
            int sl=0,se=co[w].size();

            while(sl+1<se)
            {
                int mid=(sl+se)/2;
                if(co[w][mid]<=q)
                {
                    sl=mid;
                }
                else
                {
                    se=mid;
                }
            }
            int an=-1;
            if(sl<co[w].size() and co[w][sl]<=q)
            {
                // cout<<q<<' '<<w<<' '<<co[w][sl]<<endl;
                an=abs(q-co[w][sl]);
            }
            sl=0,se=co[w].size();
            while(sl+1<se)
            {
                int mid=(sl+se)/2;
                if(co[w][mid]>q)
                {
                    se=mid;
                }
                else
                {
                    sl=mid;
                }
            }
            if(sl<co[w].size() and co[w][sl]>q)
            {
                se=sl;
            }
            sl=se;
            // sl=se;
            if(sl<co[w].size() and co[w][sl]>q)
            {
                // cout<<"for "<<q<<" have greater "<<co[w][sl]<<endl;
                if(an==-1)
                    an=abs(q-co[w][sl]);
                else
                {
                    an=min(an,abs(q-co[w][sl]));
                }
            }
            hg.push_back(an);
        }
        return hg;
    }
};
