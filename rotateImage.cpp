class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int column, row, temp;
        int max_column_number = matrix.size();
        int max_row_number = matrix[0].size();
            for (column = 0; column < max_column_number; ++column) {
                for (row = 0 ; row < max_row_number / 2; ++row) {
                    temp = matrix[column][row];
                    matrix[column][row] = matrix[column][max_row_number - row - 1];
                    matrix[column][max_row_number - row - 1] = temp;
                }
            }
            for (row = 0 ; row < max_row_number - 1; ++row) {
                for (column = 0; column < max_column_number - row - 1; ++column) {
                    temp = matrix[column][row];
                    matrix[column][row] = matrix[max_column_number - row - 1]                                                     [max_row_number - column - 1];
                    matrix[max_column_number - row - 1][max_row_number - column - 1] =                                               temp;
                }
        }
    }
};
