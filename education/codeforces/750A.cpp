#include<bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    int n, k; cin >> n >> k;

    for (int i = n; i > 0; i--) {
        if (240 - 5*i*(i+1)/2 >= k) {
            cout << i << endl;
            return 0;
        }
    }
}