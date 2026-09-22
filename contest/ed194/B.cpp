#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        ll ans = 0, x, y, k, c = 0; cin >> x >> y >> k;

        for (ll i = 0; i <= y-2*x && i < k; i++) {
            ans += y-x-(y-x)/(x+i)*(x+i);
            c++;
        }

        k -= c;
        ans += k*y-k*x;

        cout << ans << "\n";
    }
}