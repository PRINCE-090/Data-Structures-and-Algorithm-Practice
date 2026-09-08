class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if( n % k != 0) return false;
        priority_queue<int,vector<int>,greater<int>>pq;
        map<int,int>mp;
        for(int num : nums){
            mp[num]++;
        }
        for(auto it : mp){
            pq.push(it.first);
        }
        while(!pq.empty()){
           int start = pq.top();
           int freq = mp[start];

           for(int i = 0;i<k;i++){
            int current = start + i;
            if(mp[current] < freq){
                return false;
            }
            mp[current] -= freq;
           }
           while(!pq.empty() && mp[pq.top()] == 0){
            pq.pop();
           }
              
        }
        return true;
    }
};