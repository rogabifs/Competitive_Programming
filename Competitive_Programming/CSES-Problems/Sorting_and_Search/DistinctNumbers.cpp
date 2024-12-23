#include <bits/stdc++.h>
using namespace std;    
typedef long long ll;


//Using vector
void solve(vector<ll> vec) {
    int count = 0;
    sort(vec.begin(), vec.end());
    for(int i = 0; i < vec.size(); i++) {
        if(vec[i]!=vec[i+1]) count++;
    }

    cout << count << endl;
}

//Using set
void solveSet(set<ll> vec, ll n) {   
    while(n--) {
        ll x;
        cin >> x;
        vec.insert(x);
    }

    cout << vec.size() << endl;
}


int main() {
    ll n, aux, x;
    vector<ll> v;
    cin >> n;
    //Using vector ----------
    // while(n--) {
    //     cin >> x;
    //     v.push_back(x); 
    // }
    //solve(v);
    //------------

    //Using set
    set<ll> s;
    solveSet(s,n);
    return 0;
}