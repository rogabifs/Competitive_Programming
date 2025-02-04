#include <bits/stdc++.h>
using namespace std;\
typedef long long ll;
#define MAX 100001

ll n, m;
vector<vector<int> > adj(MAX);
vector<bool>visited(MAX, false);

void dfs(ll city) {
    if(visited[city]) return;
    visited[city] = true;
    for(auto neighborCity : adj[city]) {
        dfs(neighborCity);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    ll aux = m ;
    vector<ll> headsProcessed;


    while (aux--)
    { 
        ll n1, n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
    
   for(ll i = 1; i <= n; i++) {
        if(!visited[i]) {
            headsProcessed.push_back(i);
            dfs(i);
        }
   }

   cout << headsProcessed.size() - 1 << endl;
   for(int i = 0; i < headsProcessed.size() - 1; i++) {
    cout << headsProcessed[i] << " " << headsProcessed[i + 1] << endl;
   }

    return 0;
}