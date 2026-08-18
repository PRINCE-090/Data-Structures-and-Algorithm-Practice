class Solution {
public:
    int hammingDistance(int x, int y) {
        int diffBits = 0;
        while( x > 0 || y > 0){
            if(((x ^ y) &1) == 1) diffBits++;
            x >>= 1;
            y >>= 1;
        }
        return diffBits;
    }
};