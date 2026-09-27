/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int>res;
        if(root == NULL) return res;
        unordered_map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        int left = 0, right = 0;
        while(!q.empty()){
            auto [node,hd] = q.front();
            q.pop();
            
           mp[hd] = node->data;
           if(node->left) {
               int lefthd = hd-1;
               q.push({node->left,lefthd});
               left = min(left,lefthd);
           }
           if(node->right){
               int righthd = hd + 1;
               q.push({node->right,righthd});
               right = max(righthd,right);
           }           
            
        }
        for(int i = left;i<=right;i++){
            res.push_back(mp[i]);
        }
        return res;
    }
};