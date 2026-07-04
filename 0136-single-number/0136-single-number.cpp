class Solution {
public:
    int singleNumber(vector<int>& nums) {
      map<int,int>mp;
      for(int num : nums){
        mp[num]++;
      }
      for(auto it : mp){
        if(it.second == 1){
          return it.first;
        }
      }
      return -1;
    }
};


class Solution {
public:
    int singleNumber(vector<int>& nums) {
     int xorr = 0;
     for(int i = 0;i<nums.size();i++){
      xorr = nums[i] ^ xorr;
     }
     return xorr;
    }
};
