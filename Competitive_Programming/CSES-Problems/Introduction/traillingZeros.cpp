#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull traillingZeros(ull n) {
    // 1 2 3 4 5 6 7 8 9 10
    // 11 12 13 14 15 16 17 18 19 20

    // 1 2 3 22 5 23 7 222 9 25
    // 11 223 13 27 35 2222 17 29 19 22225

    // O numero de zeros é determinado pelo numero de 5's no produtorio
   // em 10! (2x5)! terao 2 0's
   // em 13! (2x5 + 3)! terao 2 0's
   if(n == 0) {
    return 0;
   }
    return n/5 + traillingZeros(n/5);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ull n;
    cin >> n;
    cout << traillingZeros(n);

    return 0;
}