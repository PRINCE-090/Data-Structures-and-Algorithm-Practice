class Solution {
  public:
    int solve(vector<int>& bt) {
        sort(bt.begin(),bt.end());
       int waitingtime = 0;
       int n = bt.size();
       int totalbursttime = bt[0];
       for(int i = 1;i<n;i++){
           waitingtime += totalbursttime;
           totalbursttime += bt[i];
       }
        return (int)(double(waitingtime/n));
    }
};