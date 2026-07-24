class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int maxones = 0,rowNo = -1;
        vector<int>ans;
        for(int i = 0;i<n;i++){
            int cnt = 0;
            for(int j = 0;j<m;j++){
                if(mat[i][j] == 1) cnt++;
            }
            if(cnt > maxones){
                maxones = cnt;
                 rowNo = i;
            }   
        }
        if(rowNo == -1) rowNo = 0;
        ans.push_back(rowNo);
        
        ans.push_back(maxones);
        return ans;
    }
};