#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000001


ll getMinCoins(ll sum, vector<ll> coins) {
    vector<ll> dp(sum + 1);
    dp[0] = 0;
    for(ll x = 1; x <= sum; x++) {
        dp[x] = INF;
        for(auto c : coins) {
            if(x - c >= 0) {
                dp[x] = min(dp[x], dp[x - c] + 1);
            }
        }
    }
    if (dp[sum] != INF) return dp[sum];
    else return -1;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, x;
    cin >> n >> x;
    vector<ll> coins;
    while (n--)
    {
        ll ni;
        cin >> ni;
        coins.push_back(ni);
    }
    
    ll result = getMinCoins(x, coins);
    cout << result;
    return 0;
}