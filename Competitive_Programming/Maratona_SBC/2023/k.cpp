#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(vector<ll>& ct, vector<ll>& cp, ll k, ll n) {
    vector<ll> result;
    // coeficientes nulos
    for(ll i = 0; i <= n; i++) {
        if(i == 0) {
            ll sum0 = 0;
            for(ll j = 0; j <= n; i++) {
                sum0 += pow(k, j) * (ct[j] + cp[j]);
            }
            result.push_back(sum0);
        } else if(i == 1) {
            ll sum1 = 0;
            for(ll j = 1; j <= n; j++) {
               sum1 += j * pow(k, j - 1) * (ct[j] + cp[j]); 
            }
            result.push_back(sum1);
        } else {
            ll sumn = cp[n] + ct[n];
            result.push_back(sumn);
        }
    }

    for(ll num : result) {
        cout << num << " ";
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;
    ll aux = n + 1;
    vector<ll> coefT;
    while(aux--) {
        ll ti;
        cin >> ti;
        coefT.push_back(ti);
    }
    aux = n+1;
    vector<ll> coefP;
    while (aux--)
    {
        ll pi;
        cin >> pi;
        coefP.push_back(pi);
    }
    
    solve(coefT,coefP,k,n);

    return 0;
}