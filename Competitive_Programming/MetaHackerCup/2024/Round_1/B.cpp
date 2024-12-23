// #include <bits/stdc++.h>
// using namespace std;
// typedef unsigned long long ll;



// void solve(ll n, ll idx) {
//     // Create a boolean array "prime[0..n]" and initialize
//     // all entries it as true. A value in prime[i] will
//     // finally be false if i is Not a prime, else true.
//     bool prime[n + 1];
//     memset(prime, true, sizeof(prime));

//     for (int p = 2; p * p <= n; p++) {
//         // If prime[p] is not changed, then it is a prime
//         if (prime[p] == true) {
//             // Update all multiples of p greater than or
//             // equal to the square of it numbers which are
//             // multiple of p and are less than p^2 are
//             // already been marked.
//             for (int i = p * p; i <= n; i += p)
//                 prime[i] = false;
//         }
//     }

//     vector<ll> primes;
//     for (int p = 2; p <= n; p++)
//         if (prime[p])
//             primes.push_back(p);

    
//    set<ll> nsubtrack;
//     for(ll i = 0; i < primes.size(); i++) {
//         if(prime[i]) {
//             for (ll j = 0; j < i; j++) {
//                 if(prime[j]) {
//                     ll diff = primes[i] - primes[j];
//                     if(diff > 1 && diff <= n && prime[diff]) {
//                         nsubtrack.insert(diff);
//                     }
//                 }
//             }
//         }
//     }   

//     cout << "Case" << " " << "#" << idx << ":" << " " << nsubtrack.size() << "\n";   
// }


// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     ll t; 
//     ll i = 0;
//     cin >> t;

//     while(t--) {
//         ll n;
//         i++;
//         cin >> n;
//         solve(n,i);
//     }


//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;


void solve(ll n, ll case_num) {
    // Cria um vetor de booleanos para identificar primos
    // vector<bool> prime(n + 1, true);
    // prime[0] = prime[1] = false; // 0 e 1 não são primos

    // for (ll p = 2; p * p <= n; p++) {
    //     if (prime[p]) {
    //         for (ll multiple = p * p; multiple <= n; multiple += p) {
    //             prime[multiple] = false;
    //         }
    //     }
    // }
    
    ll divi[100000000];
    

    // Coleta todos os números primos em um vetor
    vector<int> primes;
    divi[1] = 1;
    for(int i = 2; i < n; i++) {
        if(divi[i] == 0) divi[i] = i, primes.push_back(i);
        for(int j : primes) {
            if(j > divi[i] or i*j > n) break;
            divi[i*j] = j;
        }
    }


    // for (ll p = 2; p <= n; p++) {
    //     if (prime[p]) {
    //         primes.push_back(p);
    //     }
    // }

    // Usando um conjunto para armazenar as diferenças N-subtractorizations
    set<ll> nsubtrack;
    ll num_primes = primes.size();
    
    for (ll i = 0; i < num_primes; i++) {
        for (ll j = 0; j < i; j++) { // j < i para evitar diferenças negativas
            ll diff = primes[i] - primes[j];
            if (diff > 1 && diff <= n ) {
                nsubtrack.insert(diff);
            }
        }
    }

    cout << "Case #" << case_num << ": " << nsubtrack.size() << "\n";   
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; 
    cin >> t;

    for (ll i = 1; i <= t; i++) {
        ll n;
        cin >> n;

        solve(n, i);
    }

    return 0;
}
