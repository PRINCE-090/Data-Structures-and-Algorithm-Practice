class Solution {
public:
  vector<string>ans;
    void solve(string num,int target,int index,string expression,long long value,long long prev){
        if(index == num.size()){
            if(value == target){
                ans.push_back(expression);
            }
            return;
        }
        long long currentNum = 0;
        for(int i = index;i < num.size();i++){
            if(i > index && num[index] == '0') break;
            currentNum = currentNum * 10 + (num[i] - '0');
            string current = num.substr(index,i-index+1);
            if(index == 0){
                solve(num,target,i+1,current,currentNum,currentNum);
            }
            else{
                solve(num, target, i + 1,expression + "+" + current,value + currentNum, currentNum);
                solve(num, target, i + 1,expression + "-" + current,value - currentNum, -currentNum);
                solve(num, target, i + 1,expression + "*" + current,value - prev + (prev * currentNum), prev *currentNum);

            }
        }
    }
    vector<string> addOperators(string num, int target) {
        solve(num,target,0,"",0,0);
        return ans;        
    }
};