#include <bits/stdc++.h>
using namespace std;

void moveDisk(int nDisks, vector<vector<int> >& moves, int fromStack, int toStack, int auxStack) {
    vector<int> aux;
    if(nDisks == 1) {
        aux.push_back(fromStack);
        aux.push_back(toStack);
        moves.push_back(aux);
        return;
    }
    moveDisk(nDisks-1,moves,fromStack, auxStack,toStack);
    aux.push_back(fromStack);
    aux.push_back(toStack);
    moves.push_back(aux);

    moveDisk(nDisks-1, moves, auxStack, toStack, fromStack);
}

void towerOfHanoi(int n) {
    vector<vector<int> > moves;
    int fromStack = 1, toStack = 3, auxStack = 2;
    moveDisk(n,moves,fromStack,toStack,auxStack);

    cout << moves.size() << "\n";
    for(auto move: moves) {
        cout << move[0] << " " << move[1] << "\n";
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    towerOfHanoi(n);

    return 0;
}