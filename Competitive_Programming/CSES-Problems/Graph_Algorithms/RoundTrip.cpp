#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100001

ll n, m;
vector<vector<ll> > adj(MAX);
vector<bool> visited(MAX, false);
vector<ll> parents(MAX, -1);
ll lastNode = -1, firstNode = -1;

bool hasCycle(ll node, ll parent) {
    visited[node] = true;
    parents[node] = parent;
    for(auto neigh : adj[node]) {
        if(neigh == parent) continue;
        if(!visited[neigh]) {
            if(hasCycle(neigh, node)) return true;
        } else {
            lastNode = node;
            firstNode = neigh;
            return true;
        }
    }
    return false;
}

void printRoute() {
    for(ll i = 1; i <= n; i++) {
        if(!visited[i] && hasCycle(i, -1)) {
            vector<ll> paths;
            paths.push_back(firstNode);
            for(ll pos = lastNode; pos != firstNode; pos = parents[pos]){
                paths.push_back(pos);
            }
            paths.push_back(firstNode);
            reverse(paths.begin(), paths.end());

            cout << paths.size() << endl;
            for(ll path : paths) {
                cout << path << " ";
            }
            return;
        }
    }
    cout << "IMPOSSIBLE";
}
    

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while(m--) {
        ll n1, n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    printRoute();
    return 0;
}