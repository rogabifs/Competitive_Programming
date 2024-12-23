#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll t, i = 0;
    cin >> t;
    while (t--)
 
    {
        vector<pair<ll, ll> > v;
        ll n;
        double maxVel = -1000000, minVel = 1000000, aux = 0;
        cin >> n;
        i++;
        double maxVeli = 0, minVeli = 0;
        while(n--) {
            double ai, bi;
            cin >> ai >> bi;
            aux++;

            if( ai > 0)
            minVeli = aux/bi;
            else
            minVeli = 0;
            if(bi > 0)
            maxVeli = aux/ai;
            else
            maxVeli = 0;

            minVel = max(maxVel, minVeli);
            maxVel = min(minVel, maxVeli);
            // cout << maxVel << " "<< minVel;  
        }
        if(minVel <= maxVel) {
            cout << "ESTOU AQUI";
            cout << minVel << "\n";
        } else {
            cout << -1 << "\n";
        }

    }
    
    return 0;
}