#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfsDiameter(ll node, ll parent, vector<ll>& toLeaf, vector<ll>& maxLenght, vector<vector<ll> >& tree) {
    vector<ll> childLenghts;
    toLeaf[node] = 0;

    for(auto child : tree[node]) {
        if(child == parent) continue;
        dfsDiameter(child, node, toLeaf, maxLenght, tree);
        toLeaf[node] = max(toLeaf[node], toLeaf[child] + 1);
        childLenghts.push_back(toLeaf[child]);
    }

    if(childLenghts.size() == 0) maxLenght[node] = 0;
    else if (childLenghts.size() == 1) maxLenght[node] = childLenghts[0] + 1;
    else {
        sort(childLenghts.rbegin(), childLenghts.rend());
        maxLenght[node] = childLenghts[0] + childLenghts[1] + 2;
    }
}

ll solve(vector<ll>& toLeaf, vector<ll>& maxLenght, vector<vector<ll> >& tree) {
    dfsDiameter(1,0,toLeaf,maxLenght,tree);
    int diameter = *max_element(maxLenght.begin(), maxLenght.end());
    return diameter;
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<vector<ll> > tree(n+1);
    vector<ll> toLeaf(n+1);
    vector<ll> maxLenght(n+1);
    for(ll i = 1; i < n; i++) {
        ll n1, n2;
        cin >> n1 >> n2;
        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }

    ll result = solve(toLeaf, maxLenght, tree);
    cout << result;
    
    return 0;
}