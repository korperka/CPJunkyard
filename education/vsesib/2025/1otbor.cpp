#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k, l, t; cin >> n >> m >> k >> l >> t;

    cout << 1LL * min(n, m) * (3 * (t / (k + l)) + (t % (k + l) >= k ? 1 : 0)) << "\n";
}