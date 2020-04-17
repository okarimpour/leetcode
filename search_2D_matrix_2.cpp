
class Solution {
public:
    bool isValid (vector<vector<int>>& matrix, int i, int j) {
        return i < matrix.size() && i >= 0 && j < matrix[0].size() && j >= 0;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool exist = true;
        std::vector<vector<int> >::iterator it;
        it = matrix [matrix.size() / 2][matrix[0].size() / 2];
        return exist;
    }
};
