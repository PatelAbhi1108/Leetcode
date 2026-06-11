class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Checking each row for duplicates
        for (int row = 0; row < 9; row++) {
            unordered_set<char> seen; // Set to store seen numbers in the row
            for (int i = 0; i < 9; i++) {
                if (board[row][i] == '.') continue; // Skip empty cells
                if (seen.count(board[row][i])) return false; // If duplicate found, return false
                seen.insert(board[row][i]); // Insert the number into the set
            }
        }
        
        // Checking each column for duplicates
        for (int col = 0; col < 9; col++) {
            unordered_set<char> seen; // Set to store seen numbers in the column
            for (int i = 0; i < 9; i++) {
                if (board[i][col] == '.') continue; // Skip empty cells
                if (seen.count(board[i][col])) return false; // If duplicate found, return false
                seen.insert(board[i][col]); // Insert the number into the set
            }
        }
        
        // Checking each 3x3 sub-box for duplicates
        for (int square = 0; square < 9; square++) {
            unordered_set<char> seen; // Set to store seen numbers in the 3x3 sub-box
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    // Calculate row and column indices for the current sub-box
                    int row = (square / 3) * 3 + i;
                    int col = (square % 3) * 3 + j;
                    
                    if (board[row][col] == '.') continue; // Skip empty cells
                    if (seen.count(board[row][col])) return false; // If duplicate found, return false
                    seen.insert(board[row][col]); // Insert the number into the set
                }
            }
        }
        
        // If all checks pass, the board is valid
        return true;
    }
};
