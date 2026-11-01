class Solution {
public:
    bool helper(int i,int j,int n,int m,int k,string &word,vector<vector<char>>&board){
        if(k >= word.size()) return true;
        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] == '.' || word[k] != board[i][j]) 
        return false;
        char orginal_char = board[i][j];
        board[i][j] = '.';
        bool temp = false;
        int x[4] = {-1,1,0,0};
        int y[4] = {0,0,-1,1};
        for(int index = 0;index<4;index++){
            temp = temp || helper(i+x[index],j + y[index],n,m,k+1,word,board);
        }
        board[i][j] = orginal_char;
        return temp;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        if(n == 0) return false;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j] == word[0]){
                    if(helper(i,j,n,m,0,word,board)) return true;
                }
            }
        }
        return false;
    }
};