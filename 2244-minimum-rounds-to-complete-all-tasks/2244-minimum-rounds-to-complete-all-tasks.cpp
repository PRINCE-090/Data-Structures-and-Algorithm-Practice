class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();
        unordered_map<int,int>mp;
        for(int num : tasks){
            mp[num]++;
        }
        int minround = 0;
        for(auto it : mp){
            if(it.second == 1) return -1;
            else if(it.second%3 == 0){
                minround += it.second/3;
            }
            else{
                minround += ceil(it.second/3)+1;
            }
        }
        return minround;
    }
};