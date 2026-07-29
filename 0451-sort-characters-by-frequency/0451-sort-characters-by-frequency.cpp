class Solution {
public:
    string frequencySort(string s) {
       vector<int>arr(256,0);
       for(int ch : s ){
        arr[ch - '0']++;
       }
       vector<pair<int,char>>ans;
       for(int i = 0;i<256;i++){
           if(arr[i] != 0){
            ans.push_back({arr[i],'0'+i});
           }
       }
       sort(ans.begin(),ans.end(),greater<pair<int,char>>());
        string res = "";
        for(int i = 0;i<ans.size();i++){
            int freq = ans[i].first;
            char s = ans[i].second;
            while(freq--){
                res+=s;
            }
        }
        return res;
    }
};