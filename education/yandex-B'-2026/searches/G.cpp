#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, x, y;
    cin >> n >> x >> y;

    ll l = 0, r = max(x, y) * n;
    while (l <= r) {
        ll m = l + (r - l) / 2;

        if (m / x + m / y < n - 1)
            l = m + 1;
        else
            r = m - 1;
    }

    cout << l + min(x, y) << "\n";
}
