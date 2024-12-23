#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll minDifference(int idx, vector<ll> v,ll sum1, ll sum2, int n) {
    // Percorrer o vetor e tomando a decisao se o numero na posicao i vai entrar para o primeiro ou para o segundo grupo e somando-os

    // Se estiver no ultimo indice entao calcula a diferenca da soma dos elementos no grupo 1 e 2
    if(idx == n) {
        return abs(sum1 - sum2);   
    }

    //Para um indice diferente do ultiimo decide que o numero vai para o grupo 1
    ll choose = minDifference(idx+1, v , sum1 + v[idx], sum2, n);

    //Para um indice diferente do ultimo decide que o umero vai para o grupo 2
    ll notChoose = minDifference(idx+1, v, sum1, sum2 + v[idx], n);

    //Apos o fim da recorrencia, analisa qual dos dois caminhos gerou a menor diferenca entre as somas dos grupos
    return min(choose, notChoose);
    
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int aux;
    vector<ll> arr;
    ll result;

    cin >> n;
    aux = n;
    while(aux) {
        ll in;
        cin >> in;
        arr.push_back(in);
        aux--;
    }

    result = minDifference(0, arr, 0, 0, n);
    cout << result;
}