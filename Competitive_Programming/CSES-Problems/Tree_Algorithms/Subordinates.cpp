#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void dfs(ll root, vector<vector<ll> >& tree,vector<ll>& children) {
    for(auto u : tree[root]) {
        dfs(u,tree, children);
        children[root] += children[u] + 1;
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
  
    vector<vector<ll> > tree(n + 1);
    for(ll i = 2; i <= n;i++) {
        ll bi;
        cin >> bi;
        tree[bi].push_back(i);
    }

    vector<ll> children(n + 1, 0);

    dfs(1, tree, children);


    for(ll i = 1; i <= n; i++) {
        cout << children[i] << " ";
    }

    return 0;
    
}