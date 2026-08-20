class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorr = 0;
        for(int i = 0;i<nums.size();i++){
            xorr ^= nums[i];
        }
        long long rightmostset = (xorr &(xorr-1)) ^ xorr;
        int xorr1 = 0, xorr2  = 0;
        for(int i =0;i<nums.size();i++){
            if(nums[i] & rightmostset){
                xorr1^=nums[i];
            }
            else{
                xorr2 ^= nums[i];
            }
        }
        return {xorr1,xorr2};
    }
};