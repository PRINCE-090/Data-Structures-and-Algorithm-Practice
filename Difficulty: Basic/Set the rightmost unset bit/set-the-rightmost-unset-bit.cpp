class Solution {
  public:
    int setBit(int n) {
        int pos = 0;
        int num = n;
        while(num > 0){
            if((num & 1) == 0) break;
            pos++;
            num >>=1;
        }
        int mask = 1 << pos;
        return (n | mask);
        
        // best approach 
        //  return n | (n+1);
        
    }
};