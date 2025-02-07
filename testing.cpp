#include<bits/stdc++.h>
// class Solution {
// public:
//     bool isSafe(int row, int col, int n, vector<vector<int>>& board){
//         int x = row;
//         int y = col;
//         while(y>=0){
//             if(board[x][y] == 1) return false;
//             y--; 
//         }
//         x = row;
//         y = col;
//         while(x>=0 && y>=0){
//             if(board[x][y] == 1) return false;
//             x--;
//             y--;
//         }
//         x = row;
//         y = col;
//         while(x<n && y>=0){
//             if(board[x][y] == 1) return false;
//             x++;
//             y--;
//         }
//         return true;
//     }

//     void solve(int col, int n, vector<vector<int>>& board, int& ans){
//         if(col == n){
//             ans++;
//             return;
//         }

//         for(int i = 0; i<n; i++){
//             if(isSafe(i, col, n, board)){
//                 board[i][col] = 1;
//                 solve(col+1, n, board, ans);
//                 board[i][col] = 0;
//             }
//         }
//     }
//     int totalNQueens(int n) {
//         int ans = 0;
//         vector<vector<int>> board(n, vector<int>(n));
//         solve(0, n, board, ans);
//         return ans;
//     }
// };
int ans_count = 0;
void print_queen(vector<vector<string>>& ans){
    for(auto i: ans){
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
    cout<<ans_count<<"-----------------------";
    cout<<endl;
}

class Solution {
public:
    bool isSafe(int row, int col, int n, vector<vector<string>>& board){
        int x = row;
        int y = col;
        while(y>=0){
            if(board[x][y] == "Q") return false;
            y--; 
        }
        x = row;
        y = col;
        while(x>=0 && y>=0){
            if(board[x][y] == "Q") return false;
            x--;
            y--;
        }
        x = row;
        y = col;
        while(x<n && y>=0){
            if(board[x][y] == "Q") return false;
            x++;
            y--;
        }
        return true;
    }
    void solve(int col, int n, vector<vector<string>>& board, vector<vector<string>>& ans){
        if(col == n){
            if(board[n-1][n-1]=="."||board[n-1][n-1]=="Q"){
                ans = board;
                ans_count++;
                print_queen(ans);
            }
            return;
        }

        for(int row = 0; row<n; row++){
            if(isSafe(row, col, n, board)){
                board[row][col] = "Q";
                solve(col+1, n, board, ans);
                board[row][col] = ".";
            }

        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> board(n, vector<string>(n, "."));
        vector<vector<string>> ans;
        solve(0, n, board, ans);
        return ans;
    }
};



int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<string>> ans = s.solveNQueens(8);
    print_queen(ans);
    return 0;
}
