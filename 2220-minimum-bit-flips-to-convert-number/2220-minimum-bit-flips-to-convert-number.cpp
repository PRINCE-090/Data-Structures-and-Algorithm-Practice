class Solution {
public:
    int minBitFlips(int start, int goal) {
        int minFlips = 0;
        while(start > 0 || goal > 0){
            if(((start ^ goal) & 1) == 1) minFlips++;
            start >>=1;
            goal >>=1;
        }
        return minFlips;
    }
};