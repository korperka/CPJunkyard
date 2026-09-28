#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll w, h, n; cin >> w >> h >> n;

    ll l = 0, r = 1;
    while ((r/w) * (r/h) < n) r *= 2;

    while (l <= r) {
        ll m = l + (r - l) / 2;

        if ((m/w) * (m/h) >= n)
            r = m-1;
        else l = m+1;
    }

    cout << l << "\n";
}
