class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxproduct = nums[0], minproduct = nums[0];
        int res = nums[0];
        for(int i = 1;i<nums.size();i++){
           int a = nums[i];
           int b = nums[i]*maxproduct;
           int c = nums[i]*minproduct;
            maxproduct = max(a,max(b,c));
            minproduct = min(a,min(b,c));
            res = max(res,max(maxproduct,minproduct));
        }
        return res;
    }
};