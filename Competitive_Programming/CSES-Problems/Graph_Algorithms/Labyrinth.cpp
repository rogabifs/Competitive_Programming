#include <bits/stdc++.h>
using namespace std;
#define INF 1001


bool isValid(int raw, int col, int n, int m,vector<vector<char> >& grid) {
    if(raw < 0 || raw >= n) return false;
    if(col < 0 || col >= m) return false;
    if(grid[raw][col] == '#') return false;
    return true;
}

vector<char> shortestPath(int raw, int col, int n, int m, vector<vector<char> >& grid, vector<pair<int, int> >& directions, map<pair<int, int>, char>& directionsDic) {
    vector<vector<int> > distance(n, vector<int>(m, INF));
    vector<vector<pair<int, int> > > parent(n, vector<pair<int, int> >(m, make_pair(-1,-1)));
    queue<pair<int,int> > q;
    bool hasB = false;

    distance[raw][col] = 0;
    q.push(make_pair(raw,col));
    pair<int, int> endPos = make_pair(-1,-1);
    pair<int, int> startPos = make_pair(raw, col);

    while(!q.empty()) {
        pair<int, int> pos = q.front();
        q.pop();
        if(grid[pos.first][pos.second] == 'B') {
            endPos = make_pair(pos.first, pos.second);
            hasB = true;
            break;
        }
        
        for(auto [dy, dx] : directions) {
            int newCol = pos.second + dx, newRaw = pos.first + dy;
            if(isValid(newRaw, newCol,n,m,grid) && distance[newRaw][newCol] == INF) {
                distance[newRaw][newCol] = distance[pos.first][pos.second] + 1;
                parent[newRaw][newCol] = make_pair(pos.first, pos.second);
                q.push(make_pair(newRaw, newCol));
            } 
        }
    }
    if(hasB) {
        vector<char> path;
        pair<int, int> currentPos = endPos;
        while(currentPos != startPos) {
            pair<int,int> previousPos = parent[currentPos.first][currentPos.second];
            int dy = currentPos.first - previousPos.first, dx = currentPos.second - previousPos.second;
            pair<int,int> direction = make_pair(dy, dx);
            char directionChar = directionsDic[direction];
            path.push_back(directionChar);
            currentPos = previousPos;
        }

        return path;
    } else { 
        vector<char> v;
        return v;
    }


}

void solve(int n, int m,vector<vector<char> >& grid, vector<pair<int, int> >& directions, map<pair<int, int>, char>& directionsDic) {

    vector<char> result;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'A') {
                result = shortestPath(i,j,n,m,grid,directions, directionsDic);
                break;
            }
        }
    }

    if(result.size() == 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << result.size()  << endl;
        for(int i = result.size() - 1; i < result.size(); i--) {
            cout << result[i];
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<pair<int, int> > directions;
    directions.push_back(make_pair(-1,0)); // up
    directions.push_back(make_pair(1,0)); // down
    directions.push_back(make_pair(0, -1)); // left
    directions.push_back(make_pair(0, 1)); // right

    map<pair<int, int>, char> directionsDic;
    directionsDic[make_pair(-1, 0)] = 'U';
    directionsDic[make_pair(1,0)] = 'D';
    directionsDic[make_pair(0, -1)] = 'L';
    directionsDic[make_pair(0, 1)] = 'R';


    int n, m;
    cin >> n >> m;
    vector<vector<char> > grid(n, vector<char>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    solve(n,m,grid,directions,directionsDic);

}