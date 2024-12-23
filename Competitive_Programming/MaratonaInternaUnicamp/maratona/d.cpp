#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, k ,aux;
    vector<ll> X;
    cin >> n >> k;
    aux = n;
    while(aux--) {
        ll u;
        cin >> u;
        X.push_back(u);   
    }

     // Calcula as somas acumuladas
    vector<ll> sum_X(n + 1, 0);     // Soma dos elementos
    vector<ll> sum_X2(n + 1, 0);    // Soma dos quadrados dos elementos

    for (ll i = 0; i < n; ++i) {
        sum_X[i + 1] = sum_X[i] + X[i];
        sum_X2[i + 1] = sum_X2[i] + X[i] * X[i];
    }

    // Inicializa a variável para o intervalo com o menor desvio padrão
    ll min_l = 0, min_r = k - 1;
    double min_std_dev = numeric_limits<double>::max();

    for (ll l = 0; l <= n - k; ++l) {
        ll r = l + k - 1;
        
        double sum = sum_X[r + 1] - sum_X[l];
        double sum_sq = sum_X2[r + 1] - sum_X2[l];
        
        double mean = sum / k;
        double variance = (sum_sq / k) - (mean * mean);
        double std_dev = sqrt(variance);
        
        if (std_dev < min_std_dev) {
            min_std_dev = std_dev;
            min_l = l;
            min_r = r;
        }
    }

    cout << min_l + 1 << " " << min_r + 1 << "\n";  // Saída de 1 baseado no índice
    cout.precision(9);  // Define a precisão para garantir precisão suficiente
    cout << fixed << min_std_dev << "\n";

    return 0;  
}