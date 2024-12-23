#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int count = s.size();
    int sum = 1;
    int rep = 0;
    for(int i = 0; i < count; i++) {
        if(s[i+1] == s[i]) sum++;
        else {
            rep = max(rep,sum);
            sum = 1;
        } 
    }

    cout << rep;
    return 0;
}