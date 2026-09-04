class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();
        string ans = "";
        int minlen = INT_MAX;
        
        for(int i = 0;i<n;i++){
            
            if(s1[i] == s2[0]){
                int p1 = i, p2 = 0;
                
                while(p1 < n && p2 < m){
                    if(s1[p1] == s2[p2]) p2++;
                    p1++;
                }
                if(p2 == m){
                    int end = p1 -1;
                    p2 = m-1;
                    
                    while(end >= i){
                        if(s1[end] == s2[p2]) p2--;
                        if(p2 < 0) break;
                        end--;
                    }
                    int start = end;
                    int len = p1 - start;
                    if(len < minlen){
                        minlen = len;
                        ans = s1.substr(start,len);
                    }
                }
            }
        }
        return ans;
        
    }
};
