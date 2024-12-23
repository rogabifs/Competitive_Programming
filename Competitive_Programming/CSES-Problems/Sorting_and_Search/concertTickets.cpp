#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> solve(vector<ll> &vn, vector<ll> &vm) {
    multiset<ll> maxPrice;
    for(auto price : vn) {
        maxPrice.insert(price);
    }

    vector<ll> result(vm.size());
    for(ll i = 0; i < vm.size(); i++) {
        int aux = vm[i];
        auto itr = maxPrice.upper_bound(aux);

        if(itr == maxPrice.begin()) {
            result[i] = -1;
        } else {
            itr--;
            result[i] = (*itr);
            maxPrice.erase(itr);
        }
    }
    return result;
}


int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    ll auxn = n, auxm = m;
    vector<ll> vn;
    while (auxn--)
    {
        ll ni;
        cin >> ni;
        vn.push_back(ni);
    }

    vector<ll> vm;
    while (auxm--)
    {
       ll mi;
       cin >> mi;
        vm.push_back(mi);
    }

    vector<ll> result = solve(vn,vm);
    for(auto element : result) {
        cout << element << endl;
    }
    
}