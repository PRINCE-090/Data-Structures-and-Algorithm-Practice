class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        int eraseneed = 0;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i = 1;i<n;i++){
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];

            if(end > start2){
                eraseneed++;
                start = min(start,start2);
                end = min(end,end2);
                continue;
            }
            else{
                start = start2;
                end = end2;
            }
        }
        return eraseneed;
    }
};