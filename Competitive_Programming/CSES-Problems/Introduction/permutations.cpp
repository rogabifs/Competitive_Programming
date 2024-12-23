#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ulli;


void permutation(ulli n) {
    if(n == 1) cout << 1;

    else if(n == 2 || n == 3) {
        cout << "NO SOLUTION";
    }
    else if (n == 4) {
        for (int j = 2; j <= n; j += 2) {
            cout << j << " ";
        }
       for(int i = 1; i <= n; i += 2) {
            cout << i << " ";
        }
    }
    else {
        for(int i = 1; i <= n; i += 2) {
            cout << i << " ";
        }

        for (int j = 2; j <= n; j += 2) {
            cout << j << " ";
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ulli n = 1;
    cin >> n;

    permutation(n);

    return 0;
}