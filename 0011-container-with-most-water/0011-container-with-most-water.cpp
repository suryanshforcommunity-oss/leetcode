class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater=0;
        int n = height.size();
        int width;
        int lp=0;
        int rp=n-1;
        while(lp<rp){
            width= rp-lp;
            int ht=min(height[lp], height[rp]);
            int area= width*ht;
            maxWater=max(maxWater,area);

            height[lp]<height[rp]? lp++ : rp--;
        }
        return maxWater;
    }
};