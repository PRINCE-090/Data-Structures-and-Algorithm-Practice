class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int ptr = n-1;
        int size = 0;
        while(s[ptr] == ' ') ptr--;
        if(ptr < 0) return 0;
        for(int i = ptr;i>=0;i--){
            if(s[i] == ' ') break;
            size++;
        }
        return size;
    }
};