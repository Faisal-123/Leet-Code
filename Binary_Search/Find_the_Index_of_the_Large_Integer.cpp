
 // This is the ArrayReader's API interface.
 // You should not implement it, or speculate about its implementation
class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int s=0,e=(int)reader.length();
        while(s+1<e)
        {
            // cout<<s<<endl;
            int mid=(s+e-(2*(e==reader.length())))/2,asx=reader.compareSub(s,mid,mid+1,min(mid+1+mid-s,reader.length()-1));
            // cout<<s<<' '<<mid<<endl;
            // cout<<mid+1<<' '<<min(mid+1+mid-s,reader.length()-1)<<endl;
            if(asx==1)
            {
                e=mid;
            }
            else if(asx==-1){
                s=mid+1;
            }
            else{
                return e-1;
            }
        }
        if(reader.compareSub(s,s,e-(e==reader.length()),e-(e==reader.length()))==1)
        {
            e=s;
        }
        return e-(e==reader.length());
    }
};
