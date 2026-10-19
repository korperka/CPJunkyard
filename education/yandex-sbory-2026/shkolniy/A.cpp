#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    vector<ll> c(n + 1, 0);
    c[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            c[i] += (c[j] % m) * (c[i - j - 1] % m);
            c[i] %= m;
        }
    }

    cout << c[n] % m << "\n";
}
