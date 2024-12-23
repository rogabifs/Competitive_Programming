#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string in;
    ll k;
    cin >> in >> k;

    string aux = in;

    sort(aux.begin(), aux.end());

    

    for(ll i = in.size() - 1; i >= 0; i--) {
        // cout << aux[i];
        auto l = in.find(aux[i]);
        // cout << l;
        // cout << in[l];
        if((l < in.size()) && (in[l] == aux[i]) && (in[l] > in[l+k]) && (l + k < in.size())) {
            char x = in[l];
            in[l] = in[l+k];
            in[l+k] = x;
        }
    }

    cout << in;

    return 0;
}