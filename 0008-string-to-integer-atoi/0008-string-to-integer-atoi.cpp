class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        long long res = 0,sign = 1,i = 0;
        while(i < n && s[i] == ' ') i++;
        if(i == s.size()) return 0;
        if(s[i] == '-'){
            sign = -1;
            i++;
        }
        else if(s[i] == '+'){
            i++;
        }
        
        while(i < n && isdigit(s[i])){
            res = (res*10)+(s[i]-'0');
            if(sign * res > INT_MAX) return INT_MAX;
            if(sign * res < INT_MIN) return INT_MIN;
            i++;
        }
        return (int)sign*res;

    }
};


 int Atoi(int i,string &s,long long &val,int sign){
     if(i == s.size()) return sign*val;
     if(!isdigit(s[i])) return sign* val;
     val = (val*10)+(s[i]-'0');
     if(sign *val > INT_MAX )return INT_MAX;
     if(sign *val < INT_MIN )return INT_MIN;
     return Atoi(i+1,s,val,sign);
   }
    int myAtoi(string s) {
        int n = s.size();
        long long res = 0,sign = 1,i = 0;
        while(i < n && s[i] == ' ') i++;
        if(i == s.size()) return 0;
        if(s[i] == '-'){
            sign = -1;
            i++;
        }
        else if(s[i] == '+'){
            i++;
        }
        long long val = 0;
         return Atoi(i,s,val,sign);

    }
