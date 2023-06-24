// 6/24/23

class Solution {
private:
    bool visited[10][10];
    vector<int> ans;

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // m: number of rows
        int m = matrix.size();
        // n: number of columns
        int n = matrix[0].size();

        // Initialize the visited matrix
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                visited[i][j] = false;


        // traverse the array ((0, 0) is at the top left corner)
        int curr[2] = {0, 0};
        int next[2] = {0, 0};
        int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // right, down, left, up
        int dir = 0;

        while (true) {
            // curr = next
            curr[0] = next[0];
            curr[1] = next[1];

            ans.push_back(matrix[curr[0]][curr[1]]);

            // mark curr as visited
            visited[curr[0]][curr[1]] = true;

            // try to move curr
            next[0] = curr[0] + direction[dir][0];
            next[1] = curr[1] + direction[dir][1];

            if (next[0] < 0 || next[0] >= m || next[1] < 0 || next[1] >= n || visited[next[0]][next[1]]) {
                dir++;
                if (dir == 4) dir = 0;

                // try to move curr again
                next[0] = curr[0] + direction[dir][0];
                next[1] = curr[1] + direction[dir][1];

                if (next[0] < 0 || next[0] >= m || next[1] < 0 || next[1] >= n || visited[next[0]][next[1]])
                    break;
            }
        }

        return ans;
    }
};
