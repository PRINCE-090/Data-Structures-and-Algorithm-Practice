class Solution {
  public:
    int pageFaults(vector<int>& pages, int c) {
        int n = pages.size();
        list<int>lru;
        unordered_map<int,list<int>::iterator>mp;
        int fault = 0;
        for(int page : pages){
            if(mp.find(page) != mp.end()){
                lru.erase(mp[page]);
                lru.push_back(page);
                mp[page] = prev(lru.end());
            }
            else{
                fault++;
                if(lru.size() == c){
                    int oldpage = lru.front();
                    lru.pop_front();
                    mp.erase(oldpage);
                }
                lru.push_back(page);
                mp[page] = prev(lru.end());
            }
        }
        return fault;
    }
};