#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        char c; cin >> c;
        string s; cin >> s;

        ll ans = 0;
        for (int i = 0; 2*i < n; i++) {
            if (s[i] != s[n-i-1]) {
                if (s[i] != c) ans++;
                if (s[n-i-1] != c) ans++;
            }
        }

        cout << ans << "\n";
    }
}