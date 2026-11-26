class Solution {
public:
    bool canAliceWin(int n) {
        if(n < 10) return false;
        int alice = 0, bob = 0;
        bool aliceTurn = false;
        int stones = 10;
        while(n > 0 && n >= stones){
            n = n-stones;
            if(aliceTurn){
                bob++;
                aliceTurn = false;
            }
            else{
                alice++;
                aliceTurn = true;
            }
            stones--;
            if(stones < 0) break;
        }
       if(alice == bob) return false;
       return true;
    }
};