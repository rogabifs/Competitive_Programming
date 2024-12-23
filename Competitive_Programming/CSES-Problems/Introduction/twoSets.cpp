#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sumOfN(ll n) {
    //Returns the sum of the first n numbers 
    ll sum = n*(n+1)/2;
    return sum;
}

vector<ll> creatVector(ll n) {
    //Creat vector of the first n numbers
    vector<ll> v(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        v[i] = i;
    }
    return v;
}

vector<ll> symmetricalSum(ll x, ll k) {
    //Calculate the symmetric sum and append the number to set 1
    vector<ll> set1;
    ll sumRequired = x/2;
    ll currentSum = 0;
    ll minIndex = 1;
    ll maxIndex = k;
    while(currentSum < sumRequired) {
        currentSum += maxIndex;   
        if(currentSum < sumRequired) {
            //Traverse symmetrically and add 
            currentSum += minIndex;
            set1.push_back(maxIndex);
            set1.push_back(minIndex);
            maxIndex--;
            minIndex++;
        } else {
            // Stop traverse
            set1.push_back(maxIndex);
            break;
        }
    }

    return set1;   
}

vector<ll> defineSet2(vector<ll> set, vector<ll> vectorOfN, ll k) {
    unordered_set<ll> set1(set.begin(), set.end()); // Convert set to unordered_set
    vector<ll> result;

    for (int num : vectorOfN) {
        if (set1.find(num) == set1.end() && num != 0) { // check if num doesnt appear in set1
            result.push_back(num);
        }
    }

    return result;
}

void twoSets(ll n) {
    ll sum = sumOfN(n);
    if(sum%2 != 0) {
        cout << "NO";
    } else {
        cout << "YES\n";
        //creat vector of n
        vector<ll> v = creatVector(n);
        //Traverse v in symmetric order
        vector<ll> set1 = symmetricalSum(sum,n);
        //Sort set1
        sort(set1.begin(), set1.end());
        //Define set2
        vector<ll> set2 = defineSet2(set1,v,n);

        cout << set1.size() << "\n";
        for(auto x: set1) {
            cout << x << " ";
        }

        cout << "\n";

        cout << set2.size() << "\n";
        for(auto x: set2) {
           cout << x << " "; 
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    twoSets(n);
    return 0;
}