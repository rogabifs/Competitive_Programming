#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ull n;
    cin >> n;

    string b;
    cin >> b;

    // A string b representa o número n
    // Calculamos 2 * n + 1 diretamente na string, onde n é grande.
    // Usamos operações em string para evitar problemas com números grandes.
    
    // O resultado 2 * n + 1 pode ser computado manipulando a string
    // sem converter o número para um tipo inteiro.

    // Calcule o comprimento da string
    int len = n;
    
    // Construa o resultado com 2 * n + 1
    // Para simplificar, como n é muito grande, faremos a operação com a representação em string
    // Vamos construir o número que representa 2*n + 1.

    string result;
    bool carry = false;
    int i = len - 1;

    // Adiciona '1' ao final da string result
    // Isso equivale a somar 2*n + 1 (em que n é a string b)
    result += '1';

    while (i >= 0) {
        if (carry) {
            if (b[i] == '9') {
                result += '0';
            } else {
                result += b[i] + 1;
                carry = false;
            }
        } else {
            result += b[i];
        }
        i--;
    }

    if (carry) {
        result += '1';
    }

    reverse(result.begin(), result.end());
    cout << result << endl;

    return 0;
}
