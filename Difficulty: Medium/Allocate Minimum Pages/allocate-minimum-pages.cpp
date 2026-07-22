class Solution {
  public:
    bool validPages(vector<int>&arr,int k,long long mid){
        int total = 0,student = 1;
        for(int i = 0;i<arr.size();i++){
            if(arr[i] > mid) return false;
            if(arr[i] + total <= mid){
                total+=arr[i];
            }
            else{
                student++;
                total = arr[i];
            }
            if(student > k) return false;
        }
        return true;
    }
    int findPages(vector<int> &arr, int k) {
        if(arr.size() < k) return -1;
        long long sum = std::reduce(arr.begin(),arr.end(),0LL);
        long long left = arr[0], right = sum;
        int minpages = -1;
        while(left <= right){
            long long mid = left +(right -left)/2;
            if(validPages(arr,k,mid)){
                minpages =mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return minpages;
        
    }
};