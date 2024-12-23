#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        unordered_map<int, int> count1, count2;
        
        // Lê e conta os elementos da primeira matriz
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int value;
                cin >> value;
                ++count1[value];
            }
        }
        
        // Lê e conta os elementos da segunda matriz
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int value;
                cin >> value;
                ++count2[value];
            }
        }
        
        // Verifica se as contagens são iguais
        bool possible = true;
        if (count1.size() != count2.size()) {
            possible = false;
        } else {
            for (const auto& pair : count1) {
                if (count2[pair.first] != pair.second) {
                    possible = false;
                    break;
                }
            }
        }
        
        // Output
        if (possible) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
