class Solution {
public:
  
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1) return strs[0];
        int n = strs.size();
        string res = "";
        sort(strs.begin(),strs.end());
        string s1 = strs[0], s2 = strs[n-1];
        for(int i = 0;i<s1.size();i++){
            if(s1[i] != s2[i]){
                break;
            }
            res+=s1[i];
        }
        return res;
    }
};