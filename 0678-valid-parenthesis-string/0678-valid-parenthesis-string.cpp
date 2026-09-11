class Solution {
public:
    bool checkValidString(string s) {
      int max_open = 0;
      int min_required = 0;

      for(char c : s){
        if(c == '('){
            max_open++;
            min_required++;
        }
        else if(c == ')'){
            max_open--;
            min_required--;
        }
        else{
            max_open++;
            min_required--;
        }
      if(max_open < 0) return false;
      if(min_required < 0) min_required = 0;
      }

      return min_required ==0;
    }
};