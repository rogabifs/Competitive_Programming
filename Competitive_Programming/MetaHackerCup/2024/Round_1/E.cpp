#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#define MOD 998244353

// Estrutura de um nó da Trie
struct TrieNode {
    TrieNode* children[26]; // Cada nó pode ter até 26 filhos
    bool isEnd; // Indica se esse nó é o fim de uma string
    
    TrieNode() {
        memset(children, 0, sizeof(children)); // Inicializa todos os filhos como nullptr
        isEnd = false;
    }
};

// Função para inserir strings na Trie
void insert(TrieNode* root, const std::string& s) {
    TrieNode* current = root;
    
    for (char c : s) {
        int index = c - 'A'; // Calcula o índice da letra (A=0, B=1, ..., Z=25)
        if (!current->children[index]) {
            current->children[index] = new TrieNode();
        }
        current = current->children[index];
    }
    
    current->isEnd = true; // Marca o fim da string
}

// Função recursiva para contar nós únicos na Trie
int countNodes(TrieNode* root) {
    if (!root) return 0;
    
    int count = 1; // Conta o nó atual
    for (int i = 0; i < 26; ++i) {
        count = (count + countNodes(root->children[i])) % MOD; // Conta todos os filhos recursivamente
    }
    
    return count;
}

// Função para gerar e inserir todas as combinações possíveis de uma string com curingas
void insertWithWildcards(TrieNode* root, const std::string& s, int pos, TrieNode* current) {
    if (pos == s.size()) {
        current->isEnd = true; // Fim da string
        return;
    }
    
    if (s[pos] == '?') {
        // Para cada curinga, consideramos todas as 26 letras
        for (int i = 0; i < 26; ++i) {
            if (!current->children[i]) {
                current->children[i] = new TrieNode();
            }
            insertWithWildcards(root, s, pos + 1, current->children[i]);
        }
    } else {
        // Inserir a letra correspondente
        int index = s[pos] - 'A';
        if (!current->children[index]) {
            current->children[index] = new TrieNode();
        }
        insertWithWildcards(root, s, pos + 1, current->children[index]);
    }
}

int main() {
    int T;
    std::cin >> T;
    
    for (int t = 1; t <= T; ++t) {
        int N;
        std::cin >> N;
        
        TrieNode* root = new TrieNode(); // Cria uma nova Trie para cada caso de teste
        
        for (int i = 0; i < N; ++i) {
            std::string s;
            std::cin >> s;
            insertWithWildcards(root, s, 0, root); // Insere todas as combinações da string com curingas
        }
        
        int totalNodes = countNodes(root) % MOD; // Conta o total de nós na Trie
        std::cout << "Case #" << t << ": " << totalNodes << std::endl;
    }
    
    return 0;
}
