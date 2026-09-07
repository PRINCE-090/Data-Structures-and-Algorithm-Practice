class Solution {
  public:
    void replaceWithRank(vector<int>& arr) {
        vector<int>temp = arr;
        int n = arr.size();
       vector<pair<int,int>>vec(n);
       for(int i = 0;i<n;i++){
           vec[i] = {arr[i],i};
       }
        stable_sort(vec.begin(),vec.end(),[](const pair <int,int>&a,
        const pair<int,int>&b){
            return a.first < b.first;
        });
        
        for(int i =0;i<n;i++){
            int index = vec[i].second;
            arr[index] = i;
        }
         
    }
};