#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
const ld eps = 1e-9;


bool eq(ld a, ld b) {
    return abs(a - b) <= eps;
}

struct pt {
    ld x, y;
    pt(ld x_ = 0, ld y_ = 0) : x(x_), y(y_) {} 
    bool operator < (const pt p) const {
        if (!eq(x, p.x)) return x < p.x;
        if (!eq(y, p.y)) return y < p.y;
        return 0; 
    }
    bool operator == (const pt p) const { 
        return eq(x, p.x) and eq(y, p.y);
    }
    pt operator + (const pt p) const { 
        return pt(x+p.x, y+p.y); 
    } 
    pt operator - (const pt p) const { 
        return pt(x-p.x, y-p.y); 
    } 
    pt operator * (const ld c) const { 
        return pt(x*c , y*c ); 
    } 
    pt operator / (const ld c) const { 
        return pt(x/c , y/c ); 
    } 
    ld operator * (const pt p) const {
        return x*p.x + y*p.y; 
    }
    ld operator ^ (const pt p) const {
        return x*p.y - y*p.x; 
    } 
    friend istream& operator >> (istream& in, pt& p) {
        return in >> p.x >> p.y;
    }
};

ld sarea(pt p, pt q, pt r) { // area com sinal
    return ((q-p)^(r-q))/2;
}

bool ccw(pt p,pt q,pt r){//sep,q,rsaoccw
    return sarea(p, q, r) > eps;
}

struct upper { 
    set<pt> se;
    set<pt>::iterator it;

    int is_under(pt p) { // 1 -> inside ; 2 -> border 
        it = se.lower_bound(p);
        if (it == se.end()) return 0;
        if (it == se.begin()) return p == *it ? 2 : 0; 
        if (ccw(p, *it, *prev(it))) return 1;
        return ccw(p, *prev(it), *it) ? 0 : 2; 
    }

    void insert(pt p) {
        if (is_under(p)) return;
        if (it != se.end()) while (next(it) != se.end() and !ccw(*next(it), *it, p))
         it = se.erase(it);
        if (it != se.begin()) while (--it != se.begin() and !ccw(p, *it, *prev(it)))
            it = se.erase(it);
        se.insert(p);
    }
};

struct dyn_hull { 
    upper U, L;
    int is_inside(pt p) {
        pt neg_p(-p.x,-p.y);
        int u = U.is_under(p), l = L.is_under(neg_p); if (!u or !l) return 0;
        return max(u, l);
    }
    void insert(pt p) {
        U.insert(p);
        pt neg_p(-p.x,-p.y);
        L.insert(neg_p); 
    }
    int size() {
        int ans = U.se.size() + L.se.size(); 
        return ans <= 2 ? ans/2 : ans-2;
    }
};



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    dyn_hull hull;
    vector<pt> vetorDePontos;
    vector<ll> result;

    ll n;
    cin >> n;

    
    while(n--) {
        ll a, b;
        cin >> a >> b;
        pt ponto;
        ponto.x = a;
        ponto.y = b; 
        hull.insert(ponto);
        vetorDePontos.push_back(ponto);
    }

    for(ll i = 0; i < vetorDePontos.size(); i++ ) {
        if (hull.is_inside(vetorDePontos[i]) == 2) {
            result.push_back(i+1);
        }
    }
     
    for (int id : result) {
        cout << id << " ";
    }
    cout << endl;

    return 0;
}

