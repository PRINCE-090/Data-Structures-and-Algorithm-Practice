class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int>arr(26,0);
        int res = 0, left = 0, maxfreq;
        for(int right = 0;right <n;right++){
            arr[s[right] - 'A']++;
            maxfreq = max(maxfreq,arr[s[right]- 'A']);

            while((right -left +1 ) - maxfreq > k){
                arr[s[left] - 'A']--;
                left++;
            }
            res = max(res,(right-left+1));
        }
        return res;
    }
};