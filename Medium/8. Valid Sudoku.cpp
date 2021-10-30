/*
    If we want to solve the problem in only one itration then we have to check 
    for row, column and box at the same time. We can divide this 9x9 grid into 
    9 small 3x3 boxes. Box No = (row/3)*3 + (col/3)
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    
        int row[9][9] = {0}, col[9][9] = {0}, box[9][9] = {0};
        
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j] != '.')
                {
                    int number = board[i][j] - '0' - 1;
                    int boxNumber = (i/3)*3 + (j/3);
                    
                    if(row[i][number] || col[j][number] || box[boxNumber][number])
                        return false;
                    
                    row[i][number] = col[j][number] = box[boxNumber][number] = 1;
                }
            }
        }
        return true;
    }
};