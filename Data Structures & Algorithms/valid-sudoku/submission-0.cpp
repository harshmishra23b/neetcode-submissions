class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int r = 0;r<9;r++){
            unordered_set<char> seen;
            for(int i=0;i<9;i++){
                if(board[r][i] == '.') continue;
                if(seen.count(board[r][i])) return false;
                seen.insert(board[r][i]);
            }
        }

        for(int c=0;c<9;c++){
            unordered_set<char> seen;
            for(int i=0;i<9;i++){
                if(board[i][c] == '.') continue;
                if(seen.count(board[i][c])) return false;
                seen.insert(board[i][c]);
            }
        }

        for(int sq = 0;sq<9;sq++){
            unordered_set<char> seen;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    int row = (sq/3)*3 + i;
                    int col = (sq%3)*3 + j;
                    if(board[row][col]=='.') continue;
                    if(seen.count(board[row][col])) return false;
                    seen.insert(board[row][col]);
                }
            }

        }

        return true;
    }
};
