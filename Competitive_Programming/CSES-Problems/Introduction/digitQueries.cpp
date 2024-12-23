#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll power(ll a, ll b) { // Calculate binary exponential to bigger values
    ll res = 1;
    while(b>0) {
        if(b & 1) {
            res = (res*a); 
        }
        a = (a*a);
        b >>= 1;    
    }
    return res;
}

void find(ll n) {
    ll dig = 1;  // number of digits
    ll totNum = 9;  // Total numbers in current digit interval

    // Find the interval of number nth ex: To n = 12, 10 <= n <= 99 for 2 digits
    while(n - dig*totNum > 0) { // Verify if the quantity of digits of interval 
        n -= dig*totNum;
        dig++;
        totNum*=10;
    }

    ll idx = n%dig; // Calcule the index of the digit
    ll num = power(10, dig - 1) + (n-1)/dig; // Find the number that have the Nth digit

    if (idx != 0) { // If the number have more than 1 dig, exclude the numbers more to his right
        num = num/power(10, dig - idx);
    }
    num =num % 10;
    cout << num << "\n";


}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll q, k, aux;
    cin >> q;
    aux = q;
    while(aux--) {
        cin >> k;
        find(k);
    }
    cout << endl;

    return 0;
}