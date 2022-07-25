class Solution {
public:
    bool visited[7][7];
    
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(solve(board, word, i, j, row, col, 0))
                    return true;
            }
        }
        return false;
    }
    
    bool isSafe(int i, int j, int &row, int &col, int index, vector<vector<char>> &board, string &word) {
        return (i >= 0 && j >= 0 && i < row && j < col && visited[i][j] == 0 && board[i][j]==word[index]);
    }
    
    bool solve(vector<vector<char>>& board, string &word, int i, int j, int &row, int &col, int index)
    {
        if(index >= word.size()) return true;
        if(isSafe(i, j, row, col, index, board, word) == false) return false;
        
        visited[i][j] = 1;
        
        bool res = solve(board, word, i, j+1, row, col, index+1) or solve(board, word, i, j-1, row, col, index+1) or
                   solve(board, word, i+1, j, row, col, index+1) or solve(board, word, i-1, j, row, col, index+1);
        
        visited[i][j] = 0;
        return res;
    }
};