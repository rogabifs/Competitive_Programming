#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// ---------------- Solution using Greedy Algorithm ----------------
// Locally optional choice: Remove the maximum digit of value from the value

// void solve(ll n, ll& count) {
//     if (n / 10 == 0) {
//         count++;
//         return;
//     } 
//     else {
//         vector<ll> digits;
//         ll aux = n;
//         while(aux > 0) {
//             ll lastDig = aux % 10; // Get last digit
//             digits.push_back(lastDig);
//             aux = aux /10; // remove last digit
//         }
//         ll maxValue = *max_element(digits.begin(), digits.end());
//         count++;
//         solve(n - maxValue, count);
//     }
// }

// ------------------- Solution using Dynamic Programming ------------
// if n = 0, f(n) = 0
// else if n > 0, f(n) = min(f(n), f(n - d) + 1). Where d is the last digit of current value of n

#define INF 1000007
ll numSteps(ll n) {
    vector<ll> dp(n + 1, INF);
    dp[0] = 0;

    for(ll i = 1; i <= n; i++) {
        ll aux = i;
        while(aux) {
            ll d = aux % 10;
            dp[i] = min(dp[i], dp[i - d] + 1);
            aux /= 10;
        }
    }

    return dp[n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    ll count = 0;
    // solve(n,count); // Solution using Greedy
    count = numSteps(n); // Solution using DP
    cout << count;
     
    return 0;
}