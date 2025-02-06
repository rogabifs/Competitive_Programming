#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100001

ll n, m;
vector<vector< ll> > adj(MAX);
vector<pair<bool, char> > visited(MAX, make_pair(0, false));
bool isPossible = false;


bool isBipartiteness(ll node, char color) {
    visited[node] = make_pair(true, color);
    for(auto neigh : adj[node]) {
        if(!visited[neigh].first) {
            char newColor;
            if(color == 'R') newColor = 'B';
            else newColor = 'R';
            if(!isBipartiteness(neigh, newColor)) return false;
        }
        else if(visited[neigh].first && visited[neigh].second == visited[node].second) return false;
    }
    return true;
}

void solve(ll n, map<char, ll> m) {
    for(ll i = 1; i <= n; i++) {
        if(!visited[i].first) {
            if(!isBipartiteness(i, 'R')) {
                cout << "IMPOSSIBLE";
                return;
            }
        }
    }

    for(ll j = 1; j <= n; j++) {
        cout << m[visited[j].second] << " ";
    }
}





int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<char,ll> teamDic;
    teamDic['R'] = 1;
    teamDic['B'] = 2;

    cin >> n >> m;
    while(m--) {
        ll n1, n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    solve(n, teamDic);
    
}