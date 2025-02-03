#include <bits/stdc++.h>
using namespace std;

class CountingRooms
{
    int n, m;
    vector<vector<char> > grid;
    vector<vector<bool> > visited;
    vector<pair<int, int> > directions;
public:
    CountingRooms(int n, int m) : n(n), m(m) {
        grid.resize(n, vector<char>(m));
        visited.resize(n, vector<bool>(m, false));
        setDirections();
        setGrid();
    }

    void setDirections() {
        directions.push_back(make_pair(-1,0)); // Up
        directions.push_back(make_pair(1,0)); // Down
        directions.push_back(make_pair(0, -1)); // Left
        directions.push_back(make_pair(0,1)); // Down
    }

    void setGrid() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                char ci;
                cin >> ci;
                grid[i][j] = ci;
            }
        }
    }

    bool isValid(int raw, int col) {
        if(col < 0 || col >= m) return false;
        if(raw < 0 || raw >= n) return false;
        if(grid[raw][col] == '#') return false;
        if(visited[raw][col]) return false;
        return true;
    }
    void dfs(int raw, int col) {
        visited[raw][col] = true;
        for(auto [dy, dx] : directions) {
            int newCol = col + dx, newRaw = raw + dy;
            if(isValid(newRaw, newCol)) dfs(newRaw,newCol);
        }
    }
    int countRooms() {
        int count = 0;
        for(int raw = 0; raw < n; raw++) {
            for(int col = 0; col < m; col++) {
                if(grid[raw][col] =='.' && isValid(raw,col)) {
                    dfs(raw,col);
                    count++;
                }
            }
        }
        return count;
    }
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    CountingRooms c(n,m);
    int result = c.countRooms();
    cout << result;
    return 0;
}