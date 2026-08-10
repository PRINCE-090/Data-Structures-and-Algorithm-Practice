class Solution {
public:
    unordered_map<char,string>f;
    void call(int idx,int n,string &temp,vector<string>&res,string digits){
      if(idx == n){
        res.push_back(temp);
        return;
      }
      string choices = f[digits[idx]];
      for(int j = 0;j<choices.size();j++){
        temp.push_back(choices[j]);
       call(idx+1,n,temp,res,digits);
       temp.pop_back();
      }
      return;
    }
    vector<string> letterCombinations(string digits) {
        f['2'] = "abc";
        f['3'] = "def";
        f['4'] = "ghi";
        f['5'] = "jkl";
        f['6'] = "mno";
        f['7'] = "pqrs";
        f['8'] = "tuv";
        f['9'] = "wxyz";

        int n = digits.size();
        string temp = "";
        vector<string>res;
        call(0,n,temp,res,digits);
        return res;
    }
};