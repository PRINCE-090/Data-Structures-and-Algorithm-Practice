class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
   if(intervals.empty()) return intervals;
   vector<vector<int>>ans;
   sort(intervals.begin(),intervals.end());
   int n = intervals.size();
   int start = intervals[0][0], end = intervals[0][1];
   for(int i = 1;i<n;i++){
    int start2 = intervals[i][0];
    int end2 = intervals[i][1];
    if(end >= start2){
      end = max(end,end2);
      continue;
    }
    else{
      ans.push_back({start,end});
      start = start2;
      end = end2;
    }
   }
   ans.push_back({start,end});
   return ans;
  }
};