/* Structure of binary tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
     void find_parent(Node*root,unordered_map<Node*,Node*>&parent){
         queue<Node*>q;
         q.push(root);
         while(!q.empty()){
             Node*node = q.front();
             q.pop();
             if(node->left){
                 q.push(node->left);
                 parent[node->left] = node;
             }
             if(node->right){
                 q.push(node->right);{
                    parent[node->right] = node;
                }
            }
        }
     }
      Node *findNode(Node *root,int target){
         if(root == NULL || root->data == target) return root;
            
       Node* left = findNode(root->left,target);
       if(left != nullptr) return left;
        return findNode(root->right,target);
      }
    int minTime(Node* root, int target) {
        if(!root) return 0;
        unordered_map<Node*,Node*>parent;
        find_parent(root,parent);
        unordered_map<Node*,bool>visited;
        queue<Node*>q;
        int timeneed = 0;
        Node *firenode = findNode(root,target);
        if(!firenode) return 0;
        q.push(firenode);
        visited[firenode] = true;
        while(!q.empty()){
            int size = q.size();
            bool flag = false;
            for(int i = 0;i<size;i++){
                Node *node = q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    visited[node->left] = true;
                    flag = true;
                    q.push(node->left);
                }
                if(node->right && !visited[node->right]){
                    visited[node->right] = true;
                    flag = true;
                    q.push(node->right);
                }
                if(parent[node] && !visited[parent[node]]){
                    visited[parent[node]] = true;
                    flag = true;
                    q.push(parent[node]);
                }
            }
            if(flag) timeneed++;
            
        }
        return timeneed;
    }
};





