class Solution {
public:
    int majorityElement(vector<int>& nums) {
    int majorityElement = 0;
    int el = 0;
    map<int,int>mp;
    for(int num : nums){
      mp[num]++;
    }
    for(auto it : mp){
        if(it.second > majorityElement){
          majorityElement = it.second;
          el = it.first;
        }
    }
        return el;
    }
};