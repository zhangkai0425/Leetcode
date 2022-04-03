class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        vector<bool> column(n,false),rboard(2*n,false),lboard(2*n,false);
        backtrace(ans,board,column,lboard,rboard,0,n);
        return ans;
    }
    void backtrace(vector<vector<string>> &ans,vector<string> &board,vector<bool>  &column,vector<bool>  &lboard,vector<bool>  &rboard,int row,int n){
        if(row == n){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(column[col]||rboard[row+col]||lboard[n-1-row+col]){
                continue;
            }
            column[col]=rboard[row+col]=lboard[n-1-row+col]=true;
            board[row][col]='Q';
            backtrace(ans,board,column,lboard,rboard,row+1,n);
            column[col]=rboard[row+col]=lboard[n-1-row+col]=false;
            board[row][col]='.';
        }
    }
};
