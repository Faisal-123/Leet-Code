class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& a, int k) {
        priority_queue<pair<float,pair<int,int>>> pq;
        for(int i=0;i<a.size();i++)
        {
            for(int j=i+1;j<a.size();j++)
            {
                pq.push({(float)a[i]/(float)a[j],{a[i],a[j]}});
                if(pq.size()>k)
                {
                    pq.pop();
                }
            }
        }
        return {pq.top().second.first,pq.top().second.second};
    }
};
