class Solution {
public:
    void generate(int open,int close,string &temp,vector<string>&res,int n){
        if(open == n && close == n){
            res.push_back(temp);
            return;
        }
        if(open < n){
            temp.push_back('(');
            generate(open+1,close,temp,res,n);
            temp.pop_back();
        }
        if(close < open){
            temp.push_back(')');
            generate(open,close+1,temp,res,n);
            temp.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        string temp;
        vector<string>res;
        int open = 0,close = 0;
        generate(open,close,temp,res,n);
        return res;
    }
};