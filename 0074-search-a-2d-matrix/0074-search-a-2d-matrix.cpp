class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        long long n = matrix.size(), m = matrix[0].size();
        long long left = 0, right = n*m-1;
        while(left <= right){
            long long mid = left+(right-left)/2;
            long long row = mid/m;
            long long col = mid%m;
            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] < target){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return false;
    }
};