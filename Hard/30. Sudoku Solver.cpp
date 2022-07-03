class Solution {
public:
    
    bool isValid(int row, int col, char c, vector<vector<char>>& board)
    {
        for(int i=0; i<board[0].size(); i++)
        {
            if(board[row][i]==c) return false; // same char already present in the row- row
            if(board[i][col]==c) return false; // same char already present in the column- col
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c) return false; // same char already present in the sub-grid
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board)
    {
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if(board[i][j]=='.')
                {
                    for(char c = '1'; c<='9'; c++)
                    {
                        if(isValid(i,j,c,board)) // tells if that row,column & sub-board contains that character or not
                        {
                            board[i][j]=c;
                            if(solve(board)==true)
                                return true;
                            else
                                board[i][j]='.'; // remove the wrong choice
                        }
                    }
                    return false; // signifies that we were not able to put any character at that position. 
                    //This may happen in case we had filled the wrong one out of the multiple options for a 
                    //position in the previous call. And, now based on that, no character can be filled here because 
                    //its violating either of the 3 rules to be valid.// 
                }
            }
        }
        return true; // given sudoku already filled
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};