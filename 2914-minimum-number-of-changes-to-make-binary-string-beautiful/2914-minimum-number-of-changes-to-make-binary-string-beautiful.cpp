class Solution {
public:
    int minChanges(string s) {
        int i = 0,j = 1;
        int n = s.size();
        int changes = 0;
        while(i < n && j < n){
            if(s[i] != s[j]){
                changes++;
            }
            i+=2;
            j+=2;
        }
        return changes;
    }
};