class Solution {
public:
    bool judgeCircle(string moves) {
        int n = moves.size();
        int x = 0, y = 0;
        for(int i = 0;i<n;i++){
            if(moves[i] == 'L'){
                y = y-1;
            }
            else if(moves[i] == 'R'){
                y = y+1;
            }
            else if(moves[i] == 'U'){
                x = x-1;
            }
            else x = x+1;
        }
        return (x == 0 && y == 0);
    }
};