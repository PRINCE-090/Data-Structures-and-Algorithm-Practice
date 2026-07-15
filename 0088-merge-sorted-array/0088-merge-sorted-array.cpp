class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
   int i = m-1, j = n-1, k = m+n-1;
   while(i >= 0 && j >= 0){
    if(nums2[j] > nums1[i]){
      swap(nums2[j] ,nums1[k]);
      j--,k--;
    }
     else{
      swap(nums1[i] , nums1[k]);
      i--, k--;
     }
   }
   while(j >= 0){
    swap(nums2[j],nums1[k]);
    k--;
    j--;
   }
  }
};