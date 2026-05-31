#include<bits/stdc++.h>

using ll = long long;

using namespace std;

int main() {
    ll n, nf = 1; cin >> n;

    for (int i = 2; i <= n; i++) {
        nf *= i;

        while (nf % 10 == 0) {
            nf /= 10;
        }

        nf %= 100000;
    }

    cout << nf%10 << "\n";
}