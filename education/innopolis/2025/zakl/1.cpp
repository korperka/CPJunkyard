#include <bits/stdc++.h>

using ll = long long;
using namespace std;

const ll MOD = 1e9+9;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        ll l, r; cin >> l >> r;
        ll ans = 0, l1 = l, r1 = r;

        if (l1 % 2 == 0) l1++;
        if (r1 % 2 == 0) r1--;

        if (l1 <= r1) {
            __int128 s = (__int128)(l1+r1)*((r1-l1)/2+1)/2;
            ans = (ans + s % MOD) % MOD;
        }

        ll n = 2;
        while (n <= r) {
            ll l2 = (l+n-1)/n, r2 = r/n;
            
            if (l2 % 2 == 0) l2++;
            if (r2 % 2 == 0) r2--;

            if (l2 > r2) {
                n *= 2;
                continue;
            }

            __int128 s = (__int128)(l2+r2)*((r2-l2)/2+1)/2;
            ans = (ans + s % MOD) % MOD;

            if (n > r / 2) break;
            n *= 2;
        }

        cout << ans << "\n";
    }
}