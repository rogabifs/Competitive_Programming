#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <tuple>
#include <numeric>
using namespace std;
typedef long long ll;

ll mdc(ll a, ll b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// ll mdc_vetor(vector<ll> vetor, ll tamanho) {
//     int resultado = vetor[0];
//     for (int i = 1; i < tamanho; ++i) {
//         resultado = mdc(resultado, vetor[i]);
//         if (resultado == 1) {
//             return 1;  
//         }
//     }
//     return resultado;
// }


// ll possui_solucao_inteira(vector<ll> coeficientes, ll tamanho, ll valor_final) {
//     ll divisor = mdc_vetor(coeficientes, tamanho);
//     return valor_final % divisor == 0;
// }

// bool euclides_estendido(ll a, ll b, ll c, ll& x, ll& y) {
//     if (b == 0) {
//         if (c % a != 0) return false;
//         x = c / a;
//         y = 0;
//         return true;
//     }

//     ll x1, y1;
//     if (!euclides_estendido(b, a % b, c, x1, y1)) return false;

//     x = y1;
//     y = x1 - (a / b) * y1;
//     return true;
// }

// // Resolver um sistema de n incógnitas
// bool resolver_equacao_diophantina(vector<ll>& coeficientes, ll c) {
//     int n = coeficientes.size();
//     vector<ll> soluções(n, 0);

//     // Verificar se há solução
//     ll divisor = coeficientes[0];
//     for (int i = 1; i < n; ++i) {
//         divisor = mdc(divisor, coeficientes[i]);
//     }
//     if (c % divisor != 0) {
//         cout << "Não há solução." << endl;
//         return false;
//     }

//     // Encontrar solução particular para o sistema
//     // Resolver o sistema por substituições sucessivas
//     for (int i = 0; i < n - 1; ++i) {
//         ll x, y;
//         if (!euclides_estendido(coeficientes[i], coeficientes[i + 1], c, x, y)) {
//             cout << "Não há solução para o sistema." << endl;
//             return false;
//         }
//         soluções[i] = x;
//         soluções[i + 1] = y;
//         c = c - coeficientes[i] * x - coeficientes[i + 1] * y;
//     }
    
//     soluções[n - 1] = c / coeficientes[n - 1];  // Última incógnita

//     cout << "Solução encontrada: ";
//     for (int i = 0; i < n; ++i) {
//         cout << "x" << i + 1 << " = " << soluções[i] << " ";
//     }
//     cout << endl;
//     return true;
// }

void solver(vector<ll> v, ll u) {
 int freeVarIndex = v.size() - 1;

    // Definir um valor para a variável livre
    ll t = 1;

    // Calcular a solução para as outras variáveis
    cout << "Solução para a(s) variável(is):" << endl;
    for (int i = 0; i < v.size(); ++i) {
        if (i <= freeVarIndex) {
            // Resolvendo a equação para a variável i
            // (u - v[freeVarIndex] * t) / v[i]
            if (v[i] != 0) {
                ll xi = (u - v[freeVarIndex] * t) / v[i];
                cout << xi << " " << endl;
            } else {
                cout << "x" << i + 1 << " não pode ser determinado diretamente porque o coeficiente é zero." << endl;
            }
        }
    }

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t, aux;
    cin >> t;
    aux = t;
    while(aux--) {
        ll n,k;
        vector<ll> v;
        cin >> n >> k;
        for(int i = 0; i < n; i++) {
            ll ai;
            cin >> ai;
            v.push_back(ai);
        }
        ll result;
        // result = possui_solucao_inteira(v,n,k);
        // if(result == 1) {
        //     cout << "YES\n" << endl;
        //     //
        // } else {
        //     cout << "NO\n" << endl;
        // }
        solver(v,k);
    }

}