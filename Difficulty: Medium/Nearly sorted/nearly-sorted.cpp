class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        int n = arr.size(), index = 0;
        priority_queue<int,vector<int>,greater<int>>pq;
         for(int i = 0;i<n;i++){
             if(i < k+1){
                 pq.push(arr[i]);
             }
             else{
                 arr[index++] = pq.top();
                 pq.pop();
                 pq.push(arr[i]);
                }
        }
       while(!pq.empty()){
            arr[index++] = pq.top();
            pq.pop();
        }
         
        
    }
};