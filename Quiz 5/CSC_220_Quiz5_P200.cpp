class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;
        
        int dir_R[] = {-1,1,0,0};
        int dir_C[] = {0,0,-1,1};

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1') {
                    islands++;

                    grid[r][c] = '0';
                    queue<pair<int,int>> Q;
                    Q.push({r,c});

                    while (!Q.empty()) {
                        auto [row, col] = Q.front();
                        Q.pop();

                        for (int dir = 0; dir < 4; dir++) {
                            int nRow = row + dir_R[dir];
                            int nCol = col+ dir_C[dir];

                            if (nRow >= 0 && nRow < rows && nCol >= 0 && nCol < cols && grid[nRow][nCol] == '1') {
                                grid[nRow][nCol] = '0';
                                Q.push({nRow,nCol});
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};