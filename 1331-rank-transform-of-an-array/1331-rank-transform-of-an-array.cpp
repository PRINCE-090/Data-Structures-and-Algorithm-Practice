class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp = arr;
        unordered_map<int,int>mp;
        sort(temp.begin(),temp.end());
        int rank = 1;
        for(int i =0;i<arr.size();i++){
            if(mp.find(temp[i]) == mp.end()){
                mp[temp[i]] = rank;
                rank++;
            }
        }
        for(int i = 0;i<arr.size();i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};