class Solution {
public:
    int maxDepth(string s) {
        int open = 0;
        int maxparen = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] =='(' ){
                open++;
                maxparen = max(maxparen,open); 
            }
            else if(s[i] == ')'){
                open--;
            }
        }
        return maxparen;
    }
};