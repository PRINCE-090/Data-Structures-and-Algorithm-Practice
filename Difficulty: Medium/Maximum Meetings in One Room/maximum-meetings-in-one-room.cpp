class Solution {
  public:
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        vector<pair<int,pair<int,int>>>meetings;
        for(int i = 0;i<s.size();i++){
            meetings.push_back({f[i],{s[i],i+1}});
        }
        vector<int>ans;
        sort(meetings.begin(),meetings.end(),[](const auto &a,const auto &b){
            if(a.first != b.first){
                return a.first < b.first;
            }
            return a.second.second < b.second.second;
        });
        int lastendtime = -1;
         for(auto it : meetings){
             int starttime = it.second.first;
             int endtime = it.first;
             int idx = it.second.second;
            if(lastendtime == -1){
                ans.push_back(idx);
                lastendtime = endtime;
            }          
            else if(lastendtime < starttime){
                lastendtime = endtime;
                ans.push_back(idx);
            }
            
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};