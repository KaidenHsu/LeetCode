class Solution {
private:
    int m, n, len;
    bool visited[6][6];

    bool dfs(vector<vector<char>>& board, string word, int cnt, int x, int y) {
        visited[x][y] = true;

        if (word[cnt] != board[x][y]) return false;
        if (cnt == len-1 && board[x][y] == word[len-1]) return true;

        int Dx[] = {0, 1, 0, -1};
        int Dy[] = {-1, 0, 1, 0};

        for (int i = 0; i < 4; i++) {
            int _x = x + Dx[i];
            int _y = y + Dy[i];

            if (_x >= 0 && _x < m && _y >= 0 && _y < n && !visited[_x][_y]) {
                if (dfs(board, word, cnt+1, _x, _y))
                    return true;
                visited[_x][_y] = false;
            }
        }

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        len = word.length();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Initialize the visited array
                for (int k = 0; k < 6; k++)
                    for (int l = 0; l < 6; l++)
                        visited[k][l] = false;

                if (dfs(board, word, 0, i, j)) return true;
            }
        }

        return false;
    }
};
