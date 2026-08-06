class Solution {
  public:
    void backtrack(vector<string>&ans,string &res,string s,int n,int idx){
        if(idx == n){
            ans.push_back(res);
            return;
        }
        res.push_back(s[idx]);
        backtrack(ans,res,s,n,idx+1);
        res.pop_back();
        
        backtrack(ans,res,s,n,idx+1);
        return;
    }
    vector<string> powerSet(string s) {
        vector<string>ans;
        string res ="";
        int n = s.size();
        backtrack(ans,res,s,n,0);
        return ans;
    }
};
