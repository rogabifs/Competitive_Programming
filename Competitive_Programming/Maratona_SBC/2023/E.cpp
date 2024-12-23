#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll binaryExponential(ll a, ll b) {
    ll res = 1;
    while(b > 0) {
        if(b&1) {
            res = (res*a);
        }
        a = (a*a);
        b >>= 1;
    }
    return res;
}


ll soma(ll x) {
    ll aux = 0;
    ll pot = 10;
    while(x >= 1) {
        aux+=x%pot;
        x = x / pot;
    }
    return aux;  
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n,k,y;
    cin >> n >> k;
    priority_queue<ll> q;
    while(n--) {
        ll fi;
        cin >> fi;
        q.push(fi);
    }

    for(ll i = 0; i < k; i++) {
        ll x = q.top();
        y = soma(x);
        ll diff = x - y;
        q.pop();
        q.push(diff);
    }

    cout << y;

    return 0;
}