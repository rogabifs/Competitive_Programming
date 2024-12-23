#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t, aux = 1;
    
    cin >> t;
    while(t--) {
        ll n, k;
        vector<ll> s;
        cin >> n >> k;
        while (n--)
        {
            ll si;
            cin >> si;
            s.push_back(si);
        }
        sort(s.begin(), s.end());
        ll nida = 0;
        if(s.size() > 1) {
            nida = s.size() - 1;
        } else {
            nida = s.size();
        }
        ll segtotal = (nida + (nida - 1))*s[0];
        if(segtotal <= k) {
            cout << "Case" << " " << "#" << aux << ":" << " " << "YES" << "\n";   
        } else {
            cout << "Case" << " " << "#" << aux << ":" << " " << "NO" << "\n";  
        }
        aux++;
    }

    return 0;
}