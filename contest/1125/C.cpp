#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        unordered_map<ll, ll> p;
        ll ans = 0;
        vector<ll> s(n-4);
        for (int i = 0; i < n-4; i++) {
            s[i] = a[i] + a[i+2] - a[i+4];
            ans += p[s[i]];
            p[s[i]]++;
        }

        for (int i = 0; i < n-6; i++) {
            if (s[i] == s[i+2]) ans--;
        }

        for (int i = 0; i < n-8; i++) {
            if (s[i] == s[i+4]) ans--;
        }

        cout << ans << "\n";
    }
}