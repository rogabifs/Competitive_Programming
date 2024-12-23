#include <bits/stdc++.h>
using namespace std;
typedef long long ull;

ull mod = pow(10,9) + 7;

void bitString(ull base, ull expo) {
    // Aply the binary exponentiation
    ull result  = 1; 
    while (expo) {  
        if(expo & 1LL) {
            result = (result*base) % mod;
        }
        base = (base * base) % mod;
        expo >>= 1LL;
    }
    cout << result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ull n;
    cin >> n;
    bitString(2LL, n);

    return 0;
}
