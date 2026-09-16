class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        vector<vector<int>>ans;
        for(int i =1;i<n;i++){
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];

            if(start2 <= end){
                start = min(start,start2);
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