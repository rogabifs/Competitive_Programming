#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, h, ai, count = 0;
    cin >> n >> h;
    while(n--) {
        cin >> ai;
        if(ai <= h) {
            count++;
        } 
    }

    cout << count << endl;

    return 0;
}

