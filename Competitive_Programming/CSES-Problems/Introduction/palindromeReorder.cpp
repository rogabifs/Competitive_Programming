#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

void palindromeReorder(string s) {
    //creat an empty array of size n
    int n = s.size();
    string arr(n, ' ');

    //creat an array of frequency to save the number of occurrence of each chart
    int freq[26] = {};  //26 is the number of chart on the alphabet
    for(int i = 0; i < n; i++) {
        freq[s[i] - 'A']++;
    }

    //Count the number of chart have odd frequency
    int count = 0;
    for(int i = 0; i < 26; i++) {
        if(freq[i]%2 != 0) {
            count++;
        }
    }

    // If more the one chart have odd frequency, then no solution exists
    if(count > 1)
    cout << "NO SOLUTION\n";
    else {
        int left = 0, right = n-1;
        for(int i  = 0; i < n; i++) {
            if(freq[s[i] - 'A']%2 != 0) {
                arr[n/2] = s[i];
                freq[s[i]-'A']--;
            }
            while(freq[s[i] - 'A'] > 0) {
                arr[left++] = arr[right--] = s[i];
                freq[s[i] - 'A'] -= 2;
            }
        }
        cout << arr;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string in;
    cin >> in;
    palindromeReorder(in);

    return 0;
}