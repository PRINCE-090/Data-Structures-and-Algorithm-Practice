/* 
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int>ans;
        int lefthd = 0, righthd = 0;
        if(root == NULL) return ans;
        unordered_map<int,int>topview;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            auto [node , hd] = q.front();
            q.pop();
            if(topview.find(hd) == topview.end()){
                topview[hd] = node->data;
            }
            if(node->left){
                int left = hd-1;
                q.push({node->left,left});
                lefthd = min(lefthd,left);
            }
             if(node->right){
                int right = hd+1;
                q.push({node->right,right});
                righthd = max(righthd,right);
            }
        }
        for(int hd = lefthd;hd <= righthd;hd++){
            ans.push_back(topview[hd]);
        }
        return ans;
        
    }
};