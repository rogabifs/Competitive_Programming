#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<pair<ll,ll> > limites;
    ll v = 4;
    while(v--) {
        ll xi,yi;
        cin >> xi >> yi;
        limites.push_back(make_pair(xi,yi));
    }
    ll n;
    cin >> n;
    vector<pair<ll,ll> > posJogador;
    while(n--) {
        ll xi,yi; 
        cin >> xi >> yi;
        posJogador.push_back(make_pair(xi, yi));
    }

    

    return 0;
}