class Solution {
  public:
   int merge(vector<int>&arr,int left,int mid,int right){
       vector<int>temp;
       int cnt = 0;
       int i = left, j = mid+1;
       while(i <= mid && j <= right){
           if(arr[i] <= arr[j]){
               temp.push_back(arr[i]);
               i++;
           }
           else{
               temp.push_back(arr[j]);
               cnt += (mid-i+1);
               j++;
           }
       }
       while(i <= mid){
           temp.push_back(arr[i]);
           i++;
       }
       while(j <= right){
           temp.push_back(arr[j]);
           j++;
       }
       for(int k = left;k<= right;k++){
           arr[k] = temp[k-left];
       }
       return cnt;
   }
    int mergesort(vector<int>&arr,int left,int right){
        int cnt = 0;
        if(left >= right) return cnt;
        long long mid = (left+right)/2;
        cnt+= mergesort(arr,left,mid);
        cnt+= mergesort(arr,mid+1,right);
        cnt+= merge(arr,left,mid,right);
        return cnt;
    }
    int inversionCount(vector<int> &arr) {
       return mergesort(arr,0,arr.size()-1);
        
    }
};