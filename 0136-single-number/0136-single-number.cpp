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