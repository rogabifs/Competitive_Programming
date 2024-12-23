#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(vector<ll>& vec, ll n, ll x) {
    sort(vec.begin(), vec.end());

    ll l = 0, h = n - 1, result = 0;
    while(h >= l) {
        if(vec[l] + vec[h] <= x) {
            result++, l++, h--;
        } else {
            result++, h--;
        }
    }
    cout << result;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, x, aux;
    cin >> n >> x;
    aux = n;
    vector<ll> v;
    while(aux--) {
        ll pi;
        cin >> pi;
        v.push_back(pi);
    }

    solve(v, n, x);

    return 0;   
}