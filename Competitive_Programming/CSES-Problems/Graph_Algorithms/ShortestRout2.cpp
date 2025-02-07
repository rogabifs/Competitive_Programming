#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100001
#define INF LLONG_MAX


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, q;

    cin >> n >> m >> q; 
    vector<vector<ll> > distances(n+1, vector<ll>(n+1, INF));
    for(ll i = 1; i <= n; i++) distances[i][i] = 0;
    while (m--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        distances[a][b] = min(distances[a][b], c);
        distances[b][a] = min(distances[b][a], c);
    }


    for(ll k = 1; k <= n; k++) {
        for(ll i = 1; i <= n; i++) {
            for(ll j = 1; j <= n; j++) {
                if(distances[i][k] < INF && distances[k][j] < INF) {
                    distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
                }
            }
        }
    }

    while (q--)
    {
        ll q1, q2;
        cin >> q1 >> q2;
        cout << (distances[q1][q2] == INF ? -1 : distances[q1][q2]) << endl;
    }
    
    return 0;
}

