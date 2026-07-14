class Solution {
  public:
    int maxLength(vector<int>& arr) {
       int n =  arr.size();
       long long sum = 0;
       unordered_map<int,int>mp;
       mp[0] = -1;
       int longest = 0;
       for(int i = 0;i<n;i++){
           sum +=arr[i];
           int target = sum;
           if(mp.find(target) != mp.end()){
               longest  = max(longest,(i-mp[target]));
           }
           else{
           mp[sum] = i;
           }
       }
       return longest;
        
    }
};