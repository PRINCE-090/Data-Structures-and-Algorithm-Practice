class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) {
        int n = arr.size();
        int exceptleafnodes = (n/2);
        for(int i = 0;i < exceptleafnodes;i++){
          int left = 2 *i +1;
          int right = 2 *i + 2;
           if(left < n){
               if(arr[i] < arr[left]) return false;
           }
           if(right < n){
               if(arr[i] < arr[right]) return false;
           }
        }
        return true;
    }
};
