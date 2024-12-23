#include <bits/stdc++.h>
using namespace std;

string s;
bool visited[7][7];
int paths = 0, steps = 0;
int reserveArray[49];

void solve(int r, int c) {
    if(r == 6 && c == 0) {
        if (steps == 48) {
            paths++;
        }
        return;
    }

    if(visited[r][c] || (
            ((c >= 1 && c <= 5 && !visited[r][c+1] && !visited[r][c-1]) &&
            ((r == 0 && visited[r+1][c]) || r == 6 && visited[r - 1][c]))
        ||
            ((r >= 1 && r <= 5 && !visited[r+1][c]) && !visited[r-1][c] &&
            ((c == 0 && visited[r][c + 1]) || (c == 6 && visited[r][c - 1])))
        ||
            (r >= 1 && r <= 5 && c >= 1 && c <= 5 && visited[r + 1][c] && visited[r - 1][c] && !visited[r][c + 1] && !visited[r][c - 1])
        ||
            (r >= 1 && r <= 5 && c >= 1 && c <= 5 && visited[r][c + 1] && visited[r][c - 1] && !visited[r+1][c] && !visited[r-1][c])

    )) return;

 
    visited[r][c] = true;

    if (reserveArray[steps] != -1) {
        switch (reserveArray[steps])
        {
        case 0:
            if(r < 6 && !visited[r + 1][c]) {
                steps++;
                solve(r+1, c); // down
                steps--;
            }
            break;
        case 1:
            if(r > 0 && !visited[r - 1][c]) {
                steps++;
                solve(r - 1, c); // up
                steps--;
            }
            break;
        case 2:
            if(c > 0 && !visited[r][c - 1]) {
                steps++;
                solve(r, c - 1); // left
                steps--;
            }
            break;
        case 3:
               if(c < 6 && !visited[r][c + 1]) {
                steps++;
                solve(r, c+1); //right
                steps--;
            }
            break;
        }
        visited[r][c] = false;
        return;
        
    }

    if(r < 6 && !visited[r + 1][c]) {
        steps++;
        solve(r+1, c); // down
        steps--;
    }

    if(r > 0 && !visited[r - 1][c]) {
        steps++;
        solve(r - 1, c); // up
        steps--;
    }

    if(c < 6 && !visited[r][c + 1]) {
        steps++;
        solve(r, c+1); //right
        steps--;
    }

    if(c > 0 && !visited[r][c - 1]) {
        steps++;
        solve(r, c - 1); // left
        steps--;
    }

    visited[r][c] = false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

   cin >> s;

   for(int i = 0; i < s.size(); i++) {
        switch (s[i])
        {
        case '?':
            reserveArray[i] = -1;
            break;
        case 'D':
            reserveArray[i] = 0;
            break;
        case 'U':
            reserveArray[i] = 1;
            break;
        case 'L':
            reserveArray[i] = 2;
            break;
        case 'R':
            reserveArray[i] = 3;
            break;
        default:
            break;
        }
   }

   solve(0,0);
   cout << paths << endl;

   return 0;
}