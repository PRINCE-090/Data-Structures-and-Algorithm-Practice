1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int n = nums.size();
5        int left = 0, right = n-1;
6        while(left <= right){
7          int mid = left+(right-left)/2;
8          if(nums[mid] == target) return mid;
9          if(nums[left] <= nums[mid]){
10            if(nums[left] <= target && nums[mid] >= target){
11               right = mid-1;
12            }
13            else {
14              left = mid+1;
15            }
16          }
17          else {
18            if(nums[mid] <= target && nums[right] >= target){
19              left = mid+1;
20            }
21            else{
22              right = mid-1;
23            }
24          }
25          
26        }
27        return -1;
28    }
29};