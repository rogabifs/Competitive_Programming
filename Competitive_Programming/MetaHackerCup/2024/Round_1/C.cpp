#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll MOD = 998244353;

ll inverse(ll a, ll mod) {
    ll m0 = mod, t, q;
    ll x0 = 0, x1 = 1;
    
    if (mod == 1) return 0; 
    while (a > 1) {

        q = a / mod;
        t = mod;

        mod = a % mod, a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) x1 += m0;

    return x1;
}

void solve(ll W, ll G, ll L, int caseNum) {
    ll exp = 0;
    ll p = 0, q = 1; // Start with E[G] = 0 in fraction form

    // Calculating expected values from W down to G
    for (ll x = W; x > G; --x) {
        ll nextE = (1 + p * 2) % MOD; // E[x] = 1 + (E[x-1] + E[x+1]) / 2
        p = (nextE * inverse(2, MOD)) % MOD; // Multiply by 1/2
        q = 1;
        
        // Check if we can gain weight
        if (x - 1 >= G) {
            // Can gain weight
            if (x - L > G) {
                // Gaining is allowed
                exp = (exp + p) % MOD;
            } else {
                // Only losing is allowed
                exp = (exp + p) % MOD;
            }
        }
    }

    // Final result in p * q^(-1) % MOD
    ll result = (exp * inverse(q, MOD)) % MOD;
    cout << "Case #" << caseNum << ": " << result << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for (int i = 1; i <= T; ++i) {
        ll W, G, L;
        cin >> W >> G >> L;
        solve(W, G, L, i);
    }

    return 0;
}