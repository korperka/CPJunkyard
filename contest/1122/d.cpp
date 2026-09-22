#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        set<ll> p;
        for (int i = 0; i < n; i++) {
            ll a; cin >> a;
            p.insert(a-i);
        }

        ll k = *p.begin(), s = 1, ans = 1;
        for (const ll &c : p) {
            if (c == k+1) {
                s++;
            } else {
                s = 1;
            }

            ans = max(ans, s);
            k = c;
        }

        cout << ans << "\n";
    }
}