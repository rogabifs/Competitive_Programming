#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

const int MOD = 998244353;

// Função para verificar se um número pode ser decodificado (entre 1 e 26)
bool isValid(const std::string &s, int start, int end) {
    if (s[start] == '0') return false; // Números com zero à esquerda não são válidos
    int num = stoi(s.substr(start, end - start + 1));
    return num >= 1 && num <= 26;
}

// Função de contagem de decodificações possíveis
int countDecodings(const std::string &s) {
    int n = s.size();
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1; // Base: há uma maneira de decodificar uma string vazia
    
    for (int i = 1; i <= n; ++i) {
        // Verificar uma letra (tamanho 1)
        if (isValid(s, i - 1, i - 1)) dp[i] = (dp[i] + dp[i - 1]) % MOD;
        
        // Verificar duas letras (tamanho 2)
        if (i > 1 && isValid(s, i - 2, i - 1)) dp[i] = (dp[i] + dp[i - 2]) % MOD;
    }
    
    return dp[n];
}

// Função de backtracking para gerar todas as combinações possíveis de uma string corrompida
void generatePossibleStrings(const std::string &s, int pos, std::string current, std::vector<std::string> &results) {
    if (pos == s.size()) {
        results.push_back(current);
        return;
    }
    
    if (s[pos] == '?') {
        for (char c = '0'; c <= '9'; ++c) {
            generatePossibleStrings(s, pos + 1, current + c, results);
        }
    } else {
        generatePossibleStrings(s, pos + 1, current + s[pos], results);
    }
}

int main() {
    int T;
    std::cin >> T;
    
    for (int t = 1; t <= T; ++t) {
        std::string E;
        int K;
        std::cin >> E >> K;
        
        // Gerar todas as possíveis strings descorrompidas
        std::vector<std::string> possibleStrings;
        generatePossibleStrings(E, 0, "", possibleStrings);
        
        // Para cada string descorrompida, contar as possíveis decodificações
        std::vector<std::pair<int, std::string> > validStrings;
        int maxDecodings = 0;
        
        for (const std::string &s : possibleStrings) {
            int decodings = countDecodings(s);
            if (decodings > maxDecodings) {
                maxDecodings = decodings;
                validStrings.clear();
            }
            if (decodings == maxDecodings) {
                validStrings.push_back(make_pair(decodings, s));
            }
        }
        
        // Ordenar lexicograficamente as strings com o máximo de decodificações
      std::sort(validStrings.begin(), validStrings.end(), [](const std::pair<int, std::string> &a, const std::pair<int, std::string> &b) {
    return a.second < b.second;
});

        
        // Imprimir o resultado
        std::string resultString = validStrings[K - 1].second;
        int resultCount = validStrings[K - 1].first;
        
        std::cout << "Case #" << t << ": " << resultString << " " << resultCount % MOD << "\n";
    }
    
    return 0;
}
