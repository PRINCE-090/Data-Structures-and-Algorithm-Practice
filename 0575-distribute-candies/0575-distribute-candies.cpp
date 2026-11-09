class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        set<int>s;
        for(int num : candyType){
            s.insert(num);
        }
        int limit = n/2;
        if(s.size() >= limit) return limit;
        return s.size();
    }
};