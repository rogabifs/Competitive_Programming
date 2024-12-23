#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;

    while(t--) {
        double n, p;
        cin >> n >> p;
        double exp = (n-1)/n;
        cout << exp;
        double diff = pow(p/100, exp) - p/100;
        cout << diff*100;
    }


    return 0;
}