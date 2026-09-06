class Solution {
  public:
  class Disjointset{
      vector<int>parent;
      public:
      Disjointset(int n){
          parent.resize(n+1);
          for(int i = 0;i<=n;i++){
              parent[i] = i;
          }
      }
      int findUpar(int node){
          if(node == parent[node]){
              return node;
          }
          return parent[node] = findUpar(parent[node]);
      }
     void unionNodes(int x,int z){
         int ulp_x = findUpar(x);
         int ulp_z = findUpar(z);
         
         if(ulp_x != ulp_z){
             parent[ulp_x] = ulp_z;
         }
     }
  };
    vector<int> DSU(int n, vector<vector<int>>& queries) {
       Disjointset ds(n);
       vector<int>ans;
       for(auto &it : queries){
          int type = it[0];
          
          if(type == 1){
              int x = it[1];
              int z = it[2];
              ds.unionNodes(x,z);
          }
          else if(type == 2){
              int x = it[1];
              ans.push_back(ds.findUpar(x));
          }
       }
       return ans;
    }
};