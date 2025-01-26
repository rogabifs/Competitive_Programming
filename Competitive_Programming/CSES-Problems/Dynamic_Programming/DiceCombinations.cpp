#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> diceValues() {
    vector<ll> v;
    for(ll i = 1; i <= 6; i++) {
        v.push_back(i);
    }
    return v;
}

ll solve(ll n) {
    ll M = 1e9 + 7;
    vector<ll> count(n+1);
    vector<ll> valuesDice = diceValues();
    count[0] = 1;
    for(ll x = 1; x <= n; x++) {
        for(auto value : valuesDice) {
            if(x - value >= 0) {
                count[x] += count[x - value];
                count[x] %= M;
            }
        }
    }

    return count[n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    ll result = solve(n);
    cout << result;

    return 0;

}