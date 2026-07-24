class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();
        int i = 0, j = n-1;
        int rowNo  = -1;
        while(i < n && j >= 0){
            if(arr[i][j] == 1){
                rowNo = i;
                j--;
            }
            else{
                i++;
            }
        }
        return rowNo;
    }
};