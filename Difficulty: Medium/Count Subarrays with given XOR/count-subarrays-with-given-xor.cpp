class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<long,int>mp;
        int n = arr.size();
        int xorr = 0,cnt = 0;
        mp[0]++;
        for(int i = 0;i<n;i++){
            xorr = xorr^arr[i];
            
            if(mp.find(xorr ^ k) != mp.end()){
                cnt+= mp[xorr^k];
            }
            mp[xorr]++;
        }
        return cnt;
        
    }
};