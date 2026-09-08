class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0),nextavailable(26,0);
        for(char ch : tasks){
            freq[ch - 'A']++;
        }
        int time = 0, completed = 0, total = tasks.size();
        while(completed < total){
            int selected = -1;
            int maxfreq = 0;
            for(int i = 0;i<26;i++){
              if(freq[i] > 0 && nextavailable[i] <= time){
                if(freq[i] > maxfreq){
                    maxfreq = freq[i];
                    selected = i;
                }
              }
            }
            if(selected != -1){
                freq[selected]--;
                nextavailable[selected] = time + n +1;
                completed++;
            }
            time++;
        }
        return time;
    }
};