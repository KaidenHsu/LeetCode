// 6/26/23

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // If the first row and first column should be set to zeros
        int first_col = 0, first_row = 0;

        for (int i = 0; i < m; i++)
            if (matrix[i][0] == 0)
                first_col = 1;

        for (int i = 0; i < n; i++)
            if (matrix[0][i] == 0)
                first_row = 1;

        // If each column should be set to zeros
        // (except the first column)
        for (int i = 1; i < n; i++)
            for (int j = 0; j < m; j++)
                if (matrix[j][i] == 0)
                    matrix[0][i] = 0;

        // If each row should be set to zeros
        // (except the first row)
        for (int i = 1; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 0)
                    matrix[i][0] = 0;

        // set the corresponding grids to zeros
        // (except the first column and first row)
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;

        // set the first column to zeros if necessary
        if (first_col)
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;

        if (first_row)
            for (int i = 0; i < n; i++)
                matrix[0][i] = 0;
    }
};
