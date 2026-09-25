// using vector 
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int,int>>v;
        vector<string>ans(n);
        for(int i = 0;i<n;i++){
            v.push_back({score[i],i});
        }
        sort(v.rbegin(),v.rend());
        for(int i = 0;i<n;i++){
            pair<int,int>rank = v[i];
            if(i == 0){
                ans[rank.second] = "Gold Medal";
            }
           else if(i == 1){
                ans[rank.second] = "Silver Medal";
            }
           else if(i == 2){
                ans[rank.second] = "Bronze Medal";
            }
            else{
                ans[rank.second] = to_string(i+1);
            }
        }
        return ans;
    }
};



// using priority_queue
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
