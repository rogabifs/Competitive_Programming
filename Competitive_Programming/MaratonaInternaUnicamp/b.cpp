#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;
    std::string n;
    std::cin >> n;

    int c = 0;
    std::string r;

    for (int i = t - 1; i >= 0; --i) {
        int d = n[i] - '0';
        int s;
        
        if (i == t - 1) {
            s = d * 2 + c + 1;
        } else {
            s = d * 2 + c;
        }

        c = s / 10;
        r += std::to_string(s % 10);
    }

    if (c > 0) {
        r += std::to_string(c);
    }

    std::reverse(r.begin(), r.end());

    std::cout << r << std::endl;

    return 0;
}