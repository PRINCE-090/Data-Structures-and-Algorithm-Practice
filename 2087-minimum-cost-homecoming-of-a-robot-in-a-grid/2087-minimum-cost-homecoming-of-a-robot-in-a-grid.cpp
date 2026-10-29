class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int startrow = startPos[0];
        int startcol = startPos[1];

        int homerow = homePos[0];
        int homecol = homePos[1];
        int cost = 0;
        if(startrow < homerow){
          for(int i = startrow + 1;i<= homerow;i++){
            cost += rowCosts[i];
          }
        }
        else {
            for(int i = startrow -1 ;i >=homerow;i--){
                cost += rowCosts[i];
            }
        }
        if(startcol < homecol){
            for(int i = startcol + 1 ;i<=homecol;i++){
                cost += colCosts[i];
            }
        }
        else {
            for(int i = startcol -1;i>= homecol;i--){
                cost += colCosts[i];
            }
        }
        return cost;
    }
};