class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        long long total_count = 0, even_count = 1, odd_count = 0;
        long long sum = 0;
        for(int num : arr){
            sum += num;

            if(sum % 2){
                (total_count += even_count) % MOD;
                odd_count++;
            }
            else{
                (total_count += odd_count)%MOD;
                even_count++;
            }
        }
        return total_count%MOD;
    }
};