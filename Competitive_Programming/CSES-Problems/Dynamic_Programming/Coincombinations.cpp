// if sum < 0, f(sum) = 0
// else if sum = 0, f(sum) = 1
// else sum > 0, f(sum) += f(sum - c)


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp(ll x, vector<ll>& coins) {
    ll M = 1e9 + 7;
    vector<ll> memoi(x + 1);
    memoi[0] = 1;
    for(ll i = 1; i <= x;i++) {
        for(auto c : coins) {
            if(i - c >= 0) {
                memoi[i] += memoi[i - c];
                memoi[i] %= M;
            }
        }
    }

    return memoi[x];
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<ll> coins;
    ll n, x, aux;
    cin >> n >> x;
    aux = n;
    while (aux--)
    {
       ll ni;
       cin >> ni;
       coins.push_back(ni);

    }
    
    ll result = dp(x, coins);
    cout << result;

    return 0;
}