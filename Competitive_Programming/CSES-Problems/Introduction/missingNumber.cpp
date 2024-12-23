#include <bits/stdc++.h>
typedef unsigned long long int ulli;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ulli n, a, b;
    vector<int> v;

    cin >> n;
    b = 0;
    while(b < n-1) {
        cin >> a;
        v.push_back(a);
        b++;
    }
    sort(v.begin(), v.end());
    int missing = 1;
    for(int i = 0; i < n-1; i++) {
        if(v[i] == missing) missing++;
        else if(v[i] > missing) break;
    }

    cout << missing;
   
    return 0;
}