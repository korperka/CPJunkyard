#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ll t; cin >> t;
    while (t--) {
        ll n, ans = 0; cin >> n;
        string s; cin >> s;

        if (s[0] == '1') {
            for (const char &c : s) {
                if (c == '0') ans++;
            }

            cout << ans << "\n";
            continue;
        }

        vector<ll> a(n);
        a[0] = 0;
        for (int i = 1; i < n; i++) {
            a[i] = a[i-1] + (s[i]=='1');
        }

        vector<ll> b(n);
        b[n-1] = 0;
        for (int i = n-2; i >= 0; i--) {
            b[i] = b[i+1]+(s[i+1] == '0');
        }

        for (int i = 0; i < n; i++) {
            a[i] += b[i];
        }

        sort(a.begin(), a.end());
        cout << a[0] << "\n";
    }
}

// 4 9 7 12