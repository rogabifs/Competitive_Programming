#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(ll nd, queue<ll> c,queue<ll> r, ll& count) {
    if(nd < c.front() && r.empty()) {
        return;
    }

    if(nd >= c.front()) {
        nd = nd - c.front();
        c.pop();
        count++;
        solve(nd,c,r,count);
    } else {
        nd += r.front();
        r.pop();
        count++;
        solve(nd,c,r,count);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll nd,nc,nr, count = 0;
    cin >> nd >> nc >> nr;
    queue<ll> c;
    queue<ll> r;
    while(nc--) {
        ll ci;
        cin >> ci;
        c.push(ci);
    }

    while(nr--) {
        ll ri;
        cin >> ri;
        r.push(ri);
    }
    
    solve(nd,c,r,count);

    cout << count << endl;

    return 0;
}