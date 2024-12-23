#include <bits/stdc++.h>
typedef unsigned long long int ulli;
using namespace std;

ulli movesCount(vector<ulli> v, ulli n) {
    ulli moves = 0;
      for(int i = 0; i < n-1; i++) {
        if(v[i+1] < v[i])  {
            moves = moves + (v[i] - v[i+1]);
            v[i+1] = v[i];
        }
    }

    return moves;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ulli n,b;
    cin >> n;

    ulli a = 0;
    vector<ulli> v;
    while(a < n) {
        cin >> b;
        v.push_back(b);
        a++;
    }

    ulli moves = movesCount(v,n);

    cout << moves;
    return 0;
}