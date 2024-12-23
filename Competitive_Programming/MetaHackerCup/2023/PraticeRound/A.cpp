#include <bits/stdc++.h>
using namespace std;

void solve(int s, int d, int k, int index) {
    bool result;
    int numPaes = 0;
    int numCarne = 0;
    int numQueijo = 0;
    vector<int> necessario;
    vector<int> possui;

    numPaes = k + 1;
    numCarne = k;
    numQueijo = k;
    necessario.push_back(numPaes);
    necessario.push_back(numCarne);
    necessario.push_back(numQueijo);

    numPaes = 2 * (s + d);
    numQueijo = s + 2*d;
    numCarne = s + 2*d;

    possui.push_back(numPaes);
    possui.push_back(numCarne);
    possui.push_back(numQueijo);

    int count = 0;
    for(int i = 0; i < 3; i++) {
        if (possui[i] >= necessario[i]) count++;
    }

    if(count == 3) cout << "Case" << " " << "#" << index << ":" << " " << "YES" << "\n";
    else cout << "Case" << " " << "#" << index << ":" << " " << "NO" << "\n";

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, s ,d, k, idx = 0;
    cin >> t;
    while(t--) {
        cin >> s >> d >> k;
        solve(s, d, k, idx + 1);
        idx += 1;
    }

    return 0;
}