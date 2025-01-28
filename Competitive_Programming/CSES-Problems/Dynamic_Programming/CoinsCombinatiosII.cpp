// if sum < 0, f(sum) = 0
// else if sum = 0, f(sum) = 1
// else if sum > 0, f(sum) += f(sum - c), where cik > cik-1 > ... > c2 > c1

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll dp(ll x, vector<ll> coins) {
    ll M = 1e9 + 7;
    vector<ll> memoiResults(x + 1);
    memoiResults[0] = 1;

    // Using external loop to traverse each coins to use only sequence in increasing order ensuring a sigle count to each sequence not duplicates.
    for( auto c : coins) {
        for(ll i = c; i <= x; i++) {
            memoiResults[i] += memoiResults[i - c];
            memoiResults[i] %= M;
        }
    }  
    
    return memoiResults[x];
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<ll> coins;
    ll n, x, aux;
    cin >> n >> x;
    aux = n;
    while(aux--) {
        ll ci;
        cin >> ci;
        coins.push_back(ci);
    }

    ll result = dp(x, coins);
    cout << result;

    return 0;
}