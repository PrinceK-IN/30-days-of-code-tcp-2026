#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int rowCheck[20];
    int lowerDiagCheck[40];
    int upperDiagCheck[40];

    void solve(int col, int n, vector<string> &board, vector<vector<string>> &allSolutions) {
        if (col == n) {
            allSolutions.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (rowCheck[row] == 0 && 
                lowerDiagCheck[row + col] == 0 && 
                upperDiagCheck[(n - 1) + (col - row)] == 0) {
                
                board[row][col] = 'Q';
                rowCheck[row] = 1;
                lowerDiagCheck[row + col] = 1;
                upperDiagCheck[(n - 1) + (col - row)] = 1;

                solve(col + 1, n, board, allSolutions);

                board[row][col] = '.';
                rowCheck[row] = 0;
                lowerDiagCheck[row + col] = 0;
                upperDiagCheck[(n - 1) + (col - row)] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> allSolutions;
        vector<string> board(n, string(n, '.'));

        for(int i = 0; i < 20; i++) rowCheck[i] = 0;
        for(int i = 0; i < 40; i++) {
            lowerDiagCheck[i] = 0;
            upperDiagCheck[i] = 0;
        }

        solve(0, n, board, allSolutions);
        return allSolutions;
    }
};