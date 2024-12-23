#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

void coinPiles(ull a, ull b) {
    //2X + Y = A ----- Y = A - 2X
    //X + 2Y = B ----- X + 2(A-2X) = B
    // X + 2A - 4X = B  
    // -3X = B - 2A
    // X = (2A - B)/3

    // Y = A - 2(2A - B)/3
    // Y = (2B - A) / 3


    if ((2 * a - b) % 3 || (2 * a - b) < 0 || (2 * b - a) % 3 || (2 * b - a) < 0) 
        cout << "NO\n";
    else
        cout << "YES\n";
} 

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ull n, a , b;
    cin >> n;
    while(n) {
        cin >> a >> b;
        coinPiles(a,b);
        n--;
    }
}