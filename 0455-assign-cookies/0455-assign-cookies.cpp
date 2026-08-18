class Solution {
public:
    int findContentChildren(vector<int>& children, vector<int>& cookies) {
        sort(children.begin(),children.end());
        sort(cookies.begin(),cookies.end());
        int res = 0, i = 0,j = 0;
        while(i < children.size() && j < cookies.size()){
            if(children[i] <= cookies[j]){
                res++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
       return res;
    }
};