class Solution {
  public:
    vector<int>toposort(int v , vector<vector<int>>adj){
        vector<int>indegree(v,0);
        for(int i = 0;i<v;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        vector<int>topo;
        for(int i = 0;i<v;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return topo;
    }
    string findOrder(vector<string> &words) {
        vector<vector<int>>adj(26);
        vector<bool>present(26,0);
        int uniquechar = 0;
        for(const string &word : words){
            for(char ch : word){
                if(!present[ch-'a']){
                    present[ch - 'a'] = true;
                    uniquechar++;
                }
            }
        }
        int n = words.size();
        for(int j = 0;j<n-1;j++){
            string s1 = words[j];
            string s2 = words[j+1];
            int len = min(s1.size(),s2.size());
            bool mismatch = false;
            for(int i = 0;i<len;i++){
                if(s1[i] != s2[i]){
                    adj[s1[i] - 'a'].push_back(s2[i] - 'a');
                    mismatch = true;
                    break;
                }
            }
            if(!mismatch && s1.size() > s2.size()){
                return "";
            }
        }
        vector<int>topo = toposort(26,adj);
        string ans = "";
        int aftertopochar = 0;
        for(auto it : topo){
           if(present[it]){
               ans += char(it + 'a');
               aftertopochar++;
               
           }
        }
        if(uniquechar > aftertopochar){
            return "";
        }
        return ans;
        
    }
};