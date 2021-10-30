/*
    We can use hashset (unordered_set) to calculate combined hash of the following to check 
    if the number is already present in the row, column or box: 
    1. "row + rowIndex + number"
    2. "col + columnIndex + number"
    3. "box + boxNumber + number"
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        unordered_set<string> s;
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j] != '.')
                {
                    int num = board[i][j] -'0'-1;
                    int boxNumber = (i/3)*3 + (j/3);
                    
                    string row = "row" + to_string(i) + to_string(num);
                    string col = "col" + to_string(j) + to_string(num);
                    string box = "box" + to_string(boxNumber) + to_string(num);
                    
                    if(s.find(row) != s.end() || s.find(col) != s.end() || s.find(box) != s.end())
                        return false;
                    
                    s.insert(row); s.insert(col); s.insert(box);
                }   
            }   
        }
        return true;
    }
};