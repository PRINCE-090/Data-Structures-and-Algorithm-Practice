class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == dividend) return 1;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(divisor == 1) return dividend;

        bool ispositive = true;
        if(dividend >= 0 && divisor < 0){
            ispositive = false;
        }
        else if(dividend < 0 && divisor > 0){
            ispositive = false;
        }

        long long n = dividend;
        long long d  = divisor;

        n = abs(n);
        d = abs(d);

        long long ans = 0, sum = 0;
        while(sum + d <= n){
            ans++;
            sum +=d;
        }
         
        if(ans > INT_MAX && ispositive){
            return INT_MAX;
        }
        if(ans > INT_MAX && !ispositive){
            return INT_MIN;
        }

        return ispositive ? ans : 0-ans;
    }
};