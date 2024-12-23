#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(vector<ll> s) {
    ll numSomaPar = 1;
    ll numSomaImpar = 0;
    ll somaAtual = 0;
    ll contador = 0;

    for(auto element : s) {
        somaAtual += element;
        if(somaAtual%2 == 0) {
            contador += numSomaImpar;
            numSomaPar++;
        } else {
            contador+= numSomaPar;
            numSomaImpar++;
        }
    }

    cout << contador << endl;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> s;
    while(n--) {
        ll ni;
        cin >> ni;
        s.push_back(ni);
    }

    solve(s);

    return 0;
}