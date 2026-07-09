class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      if(nums.size() ==0) return 0;
      int n = nums.size();
      int maxseq = 1;
      unordered_set<int>st;
      for(int num : nums){
        st.insert(num);
      }
      for(auto it : st){
        if(st.find(it -1) ==st.end()){
          int seq = 1;
          int x = it;

          while(st.find(x+1) != st.end()){
            seq++;
            x = x+1;
          }
          maxseq = max(maxseq,seq);
        }
      }
      return maxseq;
      }
};