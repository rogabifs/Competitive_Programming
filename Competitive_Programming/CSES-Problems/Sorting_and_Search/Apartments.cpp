#include <bits/stdc++.h>
using namespace std;
typedef int ll;

void solve(vector<ll>& ds, vector<ll>& s, ll n,ll m, ll k) {
    sort(ds.begin(), ds.end());
    sort(s.begin(), s.end());

    ll auxDS = 0, auxS = 0, result = 0;
    while(auxDS < n && auxS < m) { 
        if(abs(ds[auxDS] - s[auxS]) <= k) {
            result += 1, auxDS += 1, auxS += 1;
        } else if (ds[auxDS] < s[auxS]){
            auxDS += 1;
        } else {
            auxS += 1;
        }
    }
    cout << result; 
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n,m,k;
    vector<ll> desiredSize;
    vector<ll> sizes;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        ll ai;
        cin >> ai;
        desiredSize.push_back(ai);
    }

    for(int j = 0; j < m; j++) {
        ll bi;
        cin >> bi;
        sizes.push_back(bi);
        
    }

    solve(desiredSize,sizes,n,m,k);

    return 0;
}