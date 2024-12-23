#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void dfs(ll no, ll pai, vector<vector<ll> >& grafo, vector<ll>& likes, vector<ll>& result) {
    ll count = 1;
    for(ll vizinho : grafo[no]) {
        if(vizinho != pai) {
            dfs(vizinho, no, grafo, likes, result);
            if(likes[vizinho - 1] > likes[no - 1]) {  
                count++;
                result.push_back(count);
            } else {
                
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n,aux1, aux2;
    vector<ll> p;
    vector<ll> v;
    cin >> n;
    aux1 = n - 1;
    aux2 = n;
    while(aux1--) {
        ll pi;
        cin >> pi;
        p.push_back(pi);
    }

    while(aux2--) {
        ll vi;
        cin >> vi;
        v.push_back(vi);
    }


    vector<vector<ll> >grafo(n+1);
    for(ll i = 0; i < n - 1; i++) {
        ll u = i + 2;
        ll v = p[i];
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    

    

    // aux = 2;
    
    // set<pair<ll,ll> > pa;
    // for(ll i = 0; i < p.size(); i++) {
    //     pa.insert(make_pair(aux, p[i]));
    //     aux++;
    // }
    
    vector<ll> result;

    // for(ll j = 2; j <= v.size(); j++) {
    //     ll p1 = 1;
    //     ll count = 1;
    //     pair<ll,ll> p(1,j);
    //     pair<ll,ll> pinv(j,1);
    //     if(pa.count(p) == 1 || pa.count(pinv) == 1) {
    //         if(v[j-1] > v[0]) {
    //             count++;
    //             result.push_back(count);
    //         } else {
    //             result.push_back(count);
    //         }
    //     }
    // }

    dfs(1,-1,grafo,v,result);

    for(ll num : result) {
        cout << num << " ";
    }

    return 0;
}