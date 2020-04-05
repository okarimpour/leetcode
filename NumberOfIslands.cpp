class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int number_of_rows = grid.size();
        if (grid.size() < 1) {
            return 0;
        }
        int number_of_columns = grid[0].size();
        int number_of_islands = 0;
        
        for (int r = 0; r < number_of_rows; r++) {
            for (int c = 0; c < number_of_columns; c++) {
                if (grid[r][c] == '1') {
                    grid[r][c] = '0';
                    number_of_islands++;
                    queue<pair<int, int>> neighbors;
                    neighbors.push({r, c});
                    while(!neighbors.empty()) {
                        pair<int, int> rc = neighbors.front();
                        neighbors.pop();
                        int row = rc.first;
                        int col = rc.second;
                        if (row - 1 >= 0 && grid[row - 1][col] == '1') {
                            neighbors.push({row - 1, col});
                            grid[row - 1][col] = '0';
                        }
                        if (row + 1 < number_of_rows && grid[row + 1][col] == '1') {
                            neighbors.push({row + 1, col});
                            grid[row + 1][col] = '0';
                        }
                        if (col - 1 >= 0 && grid[row][col - 1] == '1') {
                            neighbors.push({row, col - 1});
                            grid[row][col - 1] = '0';
                        }
                        if (col + 1 < number_of_columns && grid[row][col + 1] == '1') {
                            neighbors.push({row, col + 1});
                            grid[row][col + 1] = '0';
                        }
                    }
                }
            }
        }
        return number_of_islands;
    }
};
