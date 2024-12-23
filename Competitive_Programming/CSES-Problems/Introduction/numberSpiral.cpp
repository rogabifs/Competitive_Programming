#include <bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;

ull numberSpiral(ull y, ull x) {

    // Descricão do algoritmo com um exemplo:
    // Pega o maior número. Este número servirá para encontrar o elemento do canto inferior direito daquele "bloco interno". Chamarei este valor de CIF.
    // Suponha que o maior numero seja 4. O elemento CIF do bloco vai ser dado por 4ˆ2 - 3.
    // Como o maior numero é par, a linha do número CIF é dado por uma sequencia decrescente. Dessa forma, para encontrar o número da coluna 3 linha 4 é necessário aumentar o valor do CIF em 1, da coluna 2 aumenta em 2 e da coluna 1 aumenta 3. 
    // Os numeros da coluna do numero CIF são dados por uma sequencia decrescente também com o elemento CIF sendo o maior número da coluna nesse bloco. Ou seja, para encontrar o valor da linha 3 coluna 4 é necessário diminuir em 1 o valor CIF, para a linha 2 diminui 2 e para a linha 1 diminui 3.
    // Se o maior número for impar a lógica será inteiramente invertida( diminuir onde aumenta no caso de par, e vice-versa)


    ull value = 0;
    ull largNum = max(y, x);
    ull numDiagonal = largNum*largNum - (largNum - 1);
    if(largNum == 1) return 1;
    else if (largNum%2 == 0){  
        if(largNum == y) {
            value =  numDiagonal + (y - x); 
        }
        else {
            value = numDiagonal - (x - y);
        }
    }
    else {
        if(largNum == y) {
            value = numDiagonal - (y - x);
        }
        else {
            value =  numDiagonal + (x - y);
        }
    }
    return value;
}

int main() {
    ull n, a, x, y;

    cin >> n;
    a = 0;
    while(a < n) {
        cin >> y >> x;
        cout << numberSpiral(y,x) << "\n";
        a++;
    }

    return 0;
}