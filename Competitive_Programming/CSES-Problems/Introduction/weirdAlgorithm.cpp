#include <bits/stdc++.h>
typedef unsigned long long int ulli;
using namespace std;

int main() {
    ulli n;
    cin >> n;
    cout << n << " ";
    while(n != 1) {
        if(n%2 == 0) {
            n/=2;
            cout << n << " ";
        } else {
            n *= 3;
            n++;
            cout << n << " ";
        }
    }

    return 0;
}