// 7/26/22
class Solution {
public:
    vector<vector<string>> ret;

    bool is_valid(vector<string> &board, int row, int col){
        // check col
        for(int i = row; i >= 0; --i)
            if(board[i][col] == 'Q') return false;
        // check left diagonal
        for(int i = row, j = col; i >= 0 && j >= 0; --i, --j)
            if(board[i][j] == 'Q') return false;
        //check right diagonal
        for(int i = row, j = col; i >= 0 && j < board.size(); --i, ++j)
            if(board[i][j] == 'Q') return false;
        return true;
    }

    void dfs(vector<string> &board, int row){
        // exit condition
        if(row == board.size()){
            ret.push_back(board);
            return;
        }
        // iterate every possible position
        for(int i = 0; i < board.size(); ++i){
            if(is_valid(board, row, i)){
                board[row][i] = 'Q';
                dfs(board, row + 1);
                board[row][i] = '.'; // back-tracking
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        if(n <= 0) return {{}};
        vector<string> board(n, string(n,'.'));
        dfs(board, 0);
        return ret;
    }
};