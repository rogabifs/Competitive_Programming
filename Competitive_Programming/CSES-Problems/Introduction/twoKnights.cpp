#include <bits/stdc++.h>
typedef unsigned long long ll;
using namespace std;

ll num(ll n) {
    ll v = (n*n*(n*n - 1)/2) - 4*(n-1)*(n-2);
    return v;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, a = 1;
    cin >> n;

    while(a <= n ) {
        cout << num(a) << "\n";
        a++;
    }

    return 0;
}