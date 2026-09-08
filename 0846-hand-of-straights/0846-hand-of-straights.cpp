class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;
        unordered_map<int,int>mp;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int num : hand){
            if(mp.find(num) == mp.end()){
                pq.push(num);
            }
            mp[num]++;
        }
        while(!pq.empty()){
            int start = pq.top();
            int freq = mp[start];

            for(int i = 0;i<groupSize;i++){
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