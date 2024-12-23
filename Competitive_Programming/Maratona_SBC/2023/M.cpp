#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define for1(i,a,n) for(int i = a; i < n; i++)
#define for2(j,a,n) for(int j = a; j < n; j++)
#define for3(k,a,n) for(int k = a; k < n; k++)

int main() {


    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector< vector<ll> > m(n, vector<ll>(n));
    auto start = std::chrono::high_resolution_clock::now(); 
    for1(i,0,n) {
        for2(j,0,n) {
            ll in;
            cin >> m[i][j];
        }
    }

    for1(i,0,n) {
        for2(j,0,n) {
            for3(k,0,n) {
                if(m[i][j] > m[i][k] + m[k][j]) {
                    cout << -1;
                    return 0;
                }
            }
            
        }
    }

    int count = 0;
    for1(i,0,n) {
        for2(j,i+1,n) {
            bool canChange = false;
            for3(k,0,n) {
                if((k != i) && (k != j) && (m[i][j] == m[i][k] + m[k][j]))
                canChange = true;
            }
            if(canChange)
            count++;
        }
    }

    cout << count << endl;

    auto end = std::chrono::high_resolution_clock::now();

    // Calcula a duração
    std::chrono::duration<double> duration = end - start;

    // Exibe o tempo de execução em segundos
    std::cout << "Tempo de execução: " << duration.count() << " segundos" << std::endl;

    return 0;
}
