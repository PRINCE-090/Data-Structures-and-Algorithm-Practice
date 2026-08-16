class Solution {
  public:
    bool checkKthBit(int n, int k) {
        int bitmask = 1 << k;
        return (n & bitmask) != 0;
        
        
        // alternate 
        // return (n >> k) & 1
    }
};