class Solution {
public:
    int hammingWeight(int n) {
        int setbits = 0;
        while(n > 0){
            if((n & 1) == 1) setbits++;
            n >>=1;
        }
        return setbits;
    }
};