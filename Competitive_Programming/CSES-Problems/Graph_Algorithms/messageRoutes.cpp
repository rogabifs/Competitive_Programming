#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100001

ll n, m, aux;
vector<vector<ll> > adj(MAX);
vector<bool> visited(MAX, false);
vector<ll> distances(MAX);
queue<ll> q;
vector<ll> parent(MAX, -1);

void shortestRoute(ll initialPos) {
    for(ll i = 1; i <= n; i++) distances[i] = MAX;
    distances[initialPos] = 0;
    q.push(initialPos);
    while(!q.empty()) {
        ll a = q.front(); q.pop();
        if(visited[a]) continue;
        visited[a] = true;
        for(auto u : adj[a]) {
            if(distances[a] + 1 < distances[u]) {
                distances[u] = distances[a] + 1;
                parent[u] = a;
                q.push(u);
            }
        } 
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
    aux = m;

    while (aux--)
    {
        ll n1, n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);

    }
    
    shortestRoute(1);
    if (distances[n] == MAX) {
        cout << "IMPOSSIBLE";
    } else {
        vector<ll> path;
        for(ll pos = n; pos != -1; pos = parent[pos]) {
            path.push_back(pos);
        }
        cout << path.size() << endl;
        for(ll i = path.size() - 1; i >= 0; i--) {
            cout << path[i] << " ";
        }
    }

    return 0;
}