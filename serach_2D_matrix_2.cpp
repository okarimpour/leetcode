class Solution {
public:
    bool isValid (vector<vector<int>>& matrix, int i, int j) {
        return i < matrix.size() && i >= 0 && j < matrix[0].size() && j >= 0;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() < 1) {
            return false;
        }
        if (matrix.size() < 2 && matrix[0].size() < 1) {
                return false;
        }
        
        int r = 0;
        int c = 0;
        while (isValid(matrix, r, c)) {
            if (matrix[r][c] == target) {
                return true;
            }
            while (matrix[r][c] < target && isValid(matrix, r, c + 1)) {
                std::cout << matrix[r][c];
                c++;
                if (matrix[r][c] == target) {
                    return true;
                }
            }
            if (isValid(matrix, r + 1, c)) {
                std::cout << matrix[r][c];
                r++;
                if (matrix[r][c] == target) {
                    return true;
                }
            }
            else {
                return false;
            }

            while (matrix[r][c] > target && isValid(matrix, r, c - 1)) {
                std::cout << matrix[r][c];
                c--;
                if (matrix[r][c] == target) {
                    return true;
                }
            }
        }
        return false;
    }
};
/* oops assumed the matrix is n by n:

 bool isValid (vector<vector<int>>& matrix, int i, int j) {
        return i < matrix.size() && i >= 0 && j < matrix[0].size() && j >= 0;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() < 1) {
            return false;
        }
        if (matrix.size() < 2 && matrix[0].size() < 1) {
                return false;
        }
        int i, j;
        int ROW = matrix.size();
        int COL = matrix[0].size();
        //std::vector<std::vector<int> >::iterator it;
        for (i = 0, j = 0; matrix [i][j] != matrix [ROW - 1][COL - 1]; ++i, ++j) {
            if (matrix[i][j] == target) {
                return true;
            }
            else if (matrix[i][j] > target) {
                for (auto it = &matrix[i][j]; isValid(matrix, i, j - 1); --it) {
                    if (*it == target) {
                        return true;
                    }
                }
                for (; isValid(matrix, i - 1, j); --i) {
                    if (matrix[i][j] == target) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
*/