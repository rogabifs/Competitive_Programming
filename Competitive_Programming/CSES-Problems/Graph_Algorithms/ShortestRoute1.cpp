#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100005
#define INF LLONG_MAX

vector<vector<pair<ll,ll> > > adj(MAX);
vector<bool> processed(MAX, false);
priority_queue<pair<ll, ll> >pq;
vector<ll> distances(MAX, INF);


void shortestPath(ll start) {
    distances[start] = 0;
    pq.push(make_pair(0,start));
    while (!pq.empty())
    {
        ll a = pq.top().second; pq.pop();
        if(processed[a]) continue;
        processed[a] = true;
        for(auto neigh : adj[a]) {
            ll node = neigh.first, w = neigh.second;
            if(distances[a] + w < distances[node]){
                distances[node] = distances[a] + w;
                pq.push(make_pair(-distances[node], node));
            }
        }
    }   
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    while (m--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        pair<ll, ll> node = make_pair(b, c);
        adj[a].push_back(node);
    }

    shortestPath(1);
    for(ll i = 1; i <= n;i++) cout << distances[i] << " ";
    
}