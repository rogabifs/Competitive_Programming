#include <bits/stdc++.h>
#include <bitset>
using namespace std;
typedef long long ll;


void grayCode(int n) {
    for(int i = 0; i < 1 << n; i++) {
        ll gray = i ^(i >> 1);
        bitset<32> foo(gray);
        string a = foo.to_string();

        for(int i = 32 - n; i < 32; i++) {
            cout << a[i];
        }
        cout << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    grayCode(n);
    
    return 0;
}