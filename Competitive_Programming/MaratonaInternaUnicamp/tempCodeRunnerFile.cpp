#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void mdc(ll a, ll b) {
   ll loops = 0;
    while (a != 0 && b != 0) {
        if (a > b) {
            loops += a / b;
            a %= b;
        } else {
            loops += b / a;
            b %= a;
        }
    }
    cout << loops << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;
    while(t--) {
        ll a,b;
        cin >> a >> b;
        mdc(a, b);  
    }
     
    return 0;  
}