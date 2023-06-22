class Solution {
public:

    int minArea(vector<vector<char>>& a, int x, int y) {
        int mx=-1,my=-1,mix=a.size(),miy=a[0].size();
        for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<a[0].size();j++)
            {
                if(a[i][j]=='1')
                {
                    mx=max(mx,i);
                    my=max(my,j);
                    mix=min(mix,i);
                    miy=min(miy,j);
                }
            }
        }
        return (mx-mix+1)*(my-miy+1);
    }
};
