class Solution {
    int m, n;
public:
    void dfs(vector<vector<char>>& matrix, int x, int y){
        if(x<0 || x>=n || y<0 ||y>=m || matrix[x][y]!='O'){
            return;
        }
        matrix[x][y] = 'T';
        dfs(matrix, x-1, y);
        dfs(matrix, x, y-1);
        dfs(matrix, x, y+1);
        dfs(matrix, x+1, y);
    }
    void solve(vector<vector<char>>& board) {
        n = board.size();
        if(n==0){
            return;
        }
        m = board[0].size();
        for(int i = 0; i < n; i++){
            dfs(board, i, 0);
            dfs(board, i, m-1);
        }
        for(int i = 0; i < m; i++){
            dfs(board, 0, i);
            dfs(board, n-1, i);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j]=='T'){
                    board[i][j] = 'O';
                }else if(board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};