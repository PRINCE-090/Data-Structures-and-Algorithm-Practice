class Solution {
  public:
    vector<int> commonSlot(vector<vector<int>> &slots1, vector<vector<int>> &slots2,
                           int d) {
        sort(slots1.begin(),slots1.end());
        sort(slots2.begin(),slots2.end());
        int n = slots1.size();
        int m = slots2.size();
        int i = 0,j = 0;
        while(i < n && j < m){
            int start1 = slots1[i][0];
            int end1 = slots1[i][1];
            
            int start2 = slots2[j][0];
            int end2 = slots2[j][1];
            
            int overlapstart = max(start1,start2);
            int overlapend = min(end1,end2);
            
            if(overlapend - overlapstart >= d){
                return {overlapstart,overlapstart+d};
            }
            if(end1 > end2){
                j++;
            }
            else{
                i++;
            }
        }
        return {};
    }
};