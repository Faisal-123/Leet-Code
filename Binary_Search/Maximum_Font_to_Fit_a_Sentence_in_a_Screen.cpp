/**
 * // This is the FontInfo's API interface.
 * // You should not implement it, or speculate about its implementation
 * class FontInfo {
 *   public:
 *     // Return the width of char ch when fontSize is used.
 *     int getWidth(int fontSize, char ch);
 *     
 *     // Return Height of any char when fontSize is used.
 *     int getHeight(int fontSize)
 * };
 */
class Solution {
public:
    int maxFont(string text, int w, int h, vector<int>& fonts, FontInfo fontInfo) {
        int s=0,e=fonts.size();
        while(s+1<e)
        {
            int mid=(s+e)/2;
            long long po=0;
            for(auto i:text)
            {
                po+=fontInfo.getWidth(fonts[mid],i);
            }
            if(fontInfo.getHeight(fonts[mid])<=h and po<=w)
            {
                s=mid;
            }
            else{
                e=mid;
            }
        }
        int mid=s;
        int po=0;
        for(auto i:text)
        {
            po+=fontInfo.getWidth(fonts[mid],i);
        }
        if(fontInfo.getHeight(fonts[mid])<=h and po<=w)
        {
            return fonts[s];
        }
        else{
            return -1;
        }

    }
};
