class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return 0;
        int left = 1;
        for(int right = 1; right <n;right++)
        {
            if(arr[left -1] != arr[right])
            {
                arr[left] = arr[right];
                left++;
            }
            
        }
        return left;
    }
};
