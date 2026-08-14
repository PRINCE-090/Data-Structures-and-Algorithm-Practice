class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int left = 0, n = fruits.size();
        int size = INT_MIN;

        for(int right = 0;right <n;right++){
            mp[fruits[right]]++;
            while(mp.size() > 2){
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0){
                    mp.erase(fruits[left]);
                }
                left++;
            }
            size = max(size,right-left+1);
             
        }
        if(size == INT_MIN) return 1;
        return size;
    }
};