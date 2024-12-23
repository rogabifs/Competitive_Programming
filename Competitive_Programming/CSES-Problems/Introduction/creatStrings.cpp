#include <bits/stdc++.h>
using namespace std;

void creatString(string s) {
    // Organiza a string em ordem 
    sort(s.begin(), s.end());
    // Cria uma estrutura onde não aceita repeticao de string
    set<string> uniqueStrings;
    // Cria um loop onde para cada iteracao a permutacao é adicionada em uniqueString
    do {
        uniqueStrings.insert(s);
    } while(next_permutation(s.begin(), s.end()));
    //Imprime o numero de strings existentes em uniqueString
    cout << uniqueStrings.size() << "\n";
    //Imprime todas as strings
    for (string str : uniqueStrings) {
        cout << str << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string in;
    cin >> in;
    creatString(in);

    return 0;
}