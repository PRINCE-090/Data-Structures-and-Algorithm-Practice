class Solution {
public:
    int findsum(int n){
        int sum = 0;
        while(n > 0){
            int digit = n%10;
            n = n/10;
            sum = sum + digit*digit;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n,fast = n;
        do{
        slow = findsum(slow);
        fast = findsum(fast);
        fast = findsum(fast);
        }while(slow != fast);
        
        return slow == 1;
    }
};