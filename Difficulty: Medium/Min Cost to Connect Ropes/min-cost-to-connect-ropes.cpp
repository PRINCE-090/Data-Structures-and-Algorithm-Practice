class Solution {
  public:
    int minCost(vector<int>& arr) {
        int cost = 0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int num : arr){
            pq.push(num);
        }
        while(pq.size() >= 2){
            int first_min = pq.top();
            pq.pop();
            int second_min = pq.top();
            pq.pop();
            long long sum = first_min + second_min;
            cost+= sum;
            pq.push(sum);
        }
        return cost;
        
    }
};