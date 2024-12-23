#include <bits/stdc++.h>
using namespace std;

//Backtracking
void solve(vector<vector<char> >& table, int row, vector<bool>& ocuCol, vector<bool>& ocuPrimDiagonal, vector<bool>& ocuSecDiagonal, int& count) {
    if(row == 8) {
        count++;
        return;
    }

    for(int col = 0; col < 8; col++) {
        if(table[row][col] == '*' || ocuCol[col] || ocuPrimDiagonal[row - col + 8] || ocuSecDiagonal[row + col]) {
            continue;
        }
        ocuCol[col] = ocuPrimDiagonal[row - col + 8] = ocuSecDiagonal[row + col] = true;
        solve(table, row + 1, ocuCol, ocuPrimDiagonal, ocuSecDiagonal, count);
        ocuCol[col] = ocuPrimDiagonal[row - col + 8] = ocuSecDiagonal[row + col] = false;
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<bool> c(8, false), p(8, false), s(8, false); 
    int aux = 0;

    vector<vector<char> > table(8, vector<char>(8));
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            char x;
            cin >> table[i][j];
        }
    } 

    solve(table, 0, c, p, s, aux);
    cout << aux;

    
    return 0;
}