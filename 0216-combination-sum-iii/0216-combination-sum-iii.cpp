class Solution {
public:
    void combination(int idx,long long sum,int k,int n,vector<int>&temp,vector<vector<int>>&ans){
        if(temp.size() == k && idx <= 10){
            if(sum == n){
                ans.push_back(temp);
            }
            return;
        }
        if(idx == 10) return;
        sum+=idx;
        temp.push_back(idx);
        combination(idx+1,sum,k,n,temp,ans);
        sum-=idx;
        temp.pop_back();
        combination(idx+1,sum,k,n,temp,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        vector<vector<int>>ans;
        combination(1,0,k,n,temp,ans);
        return ans;
    }
};