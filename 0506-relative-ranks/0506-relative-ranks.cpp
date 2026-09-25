class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        priority_queue<pair<int,int>>pq;
        vector<string>ans(n);
        for(int i = 0;i<n;i++){
           pq.push({score[i],i});
        }
         int i = 0;
        while(!pq.empty()){
            if(i == 0){
                ans[pq.top().second] = "Gold Medal";
                i++;
            }
           else if(i == 1){
                ans[pq.top().second] = "Silver Medal";
                i++;
            }
           else if(i == 2){
                ans[pq.top().second] = "Bronze Medal";
                i++;
            }
            else{
                ans[pq.top().second] = to_string(i+1);
                i++;
            }
            pq.pop();
        }
        return ans;
    }
};